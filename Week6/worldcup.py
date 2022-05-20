# Simulate a sports tournament

import csv
from sys import argv, exit
import random


def main():

    # Number of simluations to run
    N = 1000

    # Ensure correct usage
    if len(argv) != 2:
        exit("Usage: python tournament.py FILENAME")

    # initialize teams
    teams = []

    # Read teams into memory from file
    with open(argv[1], "r") as file:

        # read teams into variable
        teams_reader = csv.DictReader(file)

        # extract data
        for row in teams_reader:

            # convert rating to int
            row["rating"] = int(row["rating"])

            # append teams
            teams.append(row)

    counts = {}
    # Simulate N tournaments and keep track of win counts

    # initialize M
    M = N

    # could have also done for i in range(M)
    while M > 0:
        # simulate tournament
        winner = simulate_tournament(teams)

        # check key
        if counts.get(winner) is None:

            # add key with count 1
            counts[winner] = 1

        else:
            # increase count for winner
            counts[winner] += 1

        # decrement M
        M = M - 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""

    # initialize winners
    winners = simulate_round(teams)

    # repeatedly simulate rounds
    while len(winners) > 1:
        winners = simulate_round(winners)

    # return winner
    return winners[0]["team"]


if __name__ == "__main__":
    main()