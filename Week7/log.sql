-- Keep a log of any SQL queries you execute as you solve the mystery.

--obtain description from crime scene reports with given street and date of theft--
SELECT description
    FROM crime_scene_reports
    WHERE street = "Humphrey Street"
    AND year = 2021
    AND month = 7
    AND day = 28;

--obtain interview log given date, time of theft--
SELECT transcript
    FROM interviews
    WHERE year = 2021
    AND month = 7
    AND transcript LIKE "%bakery%";

--obtain license plate from bakery security log given street, date, time of theft--
SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute BETWEEN 5 AND 25
    AND activity = "exit";

--obtain info for call in timeframe per interview--
SELECT *
    FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60;

--obtain thief passport_number from caller numbers and license plates--
SELECT passport_number
    FROM people
    WHERE phone_number IN
        (SELECT caller
        FROM phone_calls
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND duration < 60)
    AND license_plate IN
        (SELECT license_plate
        FROM bakery_security_logs
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND hour = 10
        AND minute BETWEEN 5 AND 25
        AND activity = "exit");

--obtain flight info for day after theft in earliest morning--
SELECT id
    FROM flights
    WHERE year = 2021
    AND month = 7
    AND day = 29
    AND hour =
        (SELECT MIN(hour)
            FROM flights
                WHERE year = 2021
                AND month = 7
                AND day = 29);

--cross reference passports on flight with potential thief passports--
SELECT passport_number
    FROM passengers
    WHERE passport_number IN
    (SELECT passport_number
        FROM people
        WHERE phone_number IN
            (SELECT caller
            FROM phone_calls
            WHERE year = 2021
            AND month = 7
            AND day = 28
            AND duration < 60)
        AND license_plate IN
            (SELECT license_plate
            FROM bakery_security_logs
            WHERE year = 2021
            AND month = 7
            AND day = 28
            AND hour = 10
            AND minute BETWEEN 5 AND 25
            AND activity = "exit"));

--obtain flight info for day after theft in earliest morning--
SELECT *
    FROM flights
    WHERE id =
    (SELECT id
        FROM flights
        WHERE year = 2021
        AND month = 7
        AND day = 29
        AND hour =
            (SELECT MIN(hour)
                FROM flights
                    WHERE year = 2021
                    AND month = 7
                    AND day = 29));

--obtain flight destination based on flight dest id--
SELECT full_name, city
    FROM airports
    WHERE id =
    (SELECT destination_airport_id
        FROM flights
        WHERE id =
        (SELECT id
            FROM flights
            WHERE year = 2021
            AND month = 7
            AND day = 29
            AND hour =
                (SELECT MIN(hour)
                    FROM flights
                        WHERE year = 2021
                        AND month = 7
                        AND day = 29)));

--obtain account numbers for timeframe per interview--
SELECT DISTINCT account_number
    FROM atm_transactions
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND transaction_type = "withdraw"
    AND atm_location = "Leggett Street";

--obtain person id based on account numbers--
SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
    (SELECT DISTINCT account_number
        FROM atm_transactions
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND transaction_type = "withdraw"
        AND atm_location = "Leggett Street");

--cross reference all current person id info--
SELECT *
    FROM people
    WHERE id IN
    (SELECT person_id
        FROM bank_accounts
        WHERE account_number IN
        (SELECT DISTINCT account_number
            FROM atm_transactions
            WHERE year = 2021
            AND month = 7
            AND day = 28
            AND transaction_type = "withdraw"
            AND atm_location = "Leggett Street"))
        AND passport_number IN
        (SELECT passport_number
            FROM people
            WHERE phone_number IN
                (SELECT caller
                FROM phone_calls
                WHERE year = 2021
                AND month = 7
                AND day = 28
                AND duration < 60)
            AND license_plate IN
                (SELECT license_plate
                FROM bakery_security_logs
                WHERE year = 2021
                AND month = 7
                AND day = 28
                AND hour = 10
                AND minute BETWEEN 5 AND 25
                AND activity = "exit"));


--obtain info for call in timeframe and from suspects--
SELECT *
    FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
    AND caller IN
    (SELECT phone_number
        FROM people
        WHERE id IN
        (SELECT person_id
            FROM bank_accounts
            WHERE account_number IN
            (SELECT DISTINCT account_number
                FROM atm_transactions
                WHERE year = 2021
                AND month = 7
                AND day = 28
                AND transaction_type = "withdraw"
                AND atm_location = "Leggett Street"))
            AND passport_number IN
            (SELECT passport_number
                FROM people
                WHERE phone_number IN
                    (SELECT caller
                    FROM phone_calls
                    WHERE year = 2021
                    AND month = 7
                    AND day = 28
                    AND duration < 60)
                AND license_plate IN
                    (SELECT license_plate
                    FROM bakery_security_logs
                    WHERE year = 2021
                    AND month = 7
                    AND day = 28
                    AND hour = 10
                    AND minute BETWEEN 5 AND 25
                    AND activity = "exit")));

--obtain info for receiver--
SELECT name
FROM people
WHERE phone_number IN
    (SELECT receiver
        FROM phone_calls
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND duration < 60
        AND caller IN
        (SELECT phone_number
            FROM people
            WHERE id IN
            (SELECT person_id
                FROM bank_accounts
                WHERE account_number IN
                (SELECT DISTINCT account_number
                    FROM atm_transactions
                    WHERE year = 2021
                    AND month = 7
                    AND day = 28
                    AND transaction_type = "withdraw"
                    AND atm_location = "Leggett Street"))
                AND passport_number IN
                (SELECT passport_number
                    FROM people
                    WHERE phone_number IN
                        (SELECT caller
                        FROM phone_calls
                        WHERE year = 2021
                        AND month = 7
                        AND day = 28
                        AND duration < 60)
                    AND license_plate IN
                        (SELECT license_plate
                        FROM bakery_security_logs
                        WHERE year = 2021
                        AND month = 7
                        AND day = 28
                        AND hour = 10
                        AND minute BETWEEN 5 AND 25
                        AND activity = "exit"))));



-- --check if suspect accomplices on flight--
-- SELECT name
--     FROM people
--     WHERE passport_number IN
--     (SELECT passport_number
--         FROM passengers
--         WHERE flight_id IN
--         (SELECT id
--             FROM flights
--             WHERE id =
--             (SELECT id
--                 FROM flights
--                 WHERE year = 2021
--                 AND month = 7
--                 AND day = 29
--                 AND hour =
--                     (SELECT MIN(hour)
--                         FROM flights
--                             WHERE year = 2021
--                             AND month = 7
--                             AND day = 29))));

-- --obtain thief accomplice info from receiver numbers and flight info--
-- SELECT passport_number, name
--     FROM people
--     WHERE phone_number IN
--         (SELECT receiver
--         FROM phone_calls
--         WHERE year = 2021
--         AND month = 7
--         AND day = 28
--         AND duration < 60)
--     AND passport_number IN
--         (SELECT passport_number
--         FROM passengers
--         WHERE flight_id =
--         (SELECT id
--             FROM flights
--             WHERE year = 2021
--             AND month = 7
--             AND day = 29
--             AND hour =
--                 (SELECT MIN(hour)
--                     FROM flights
--                         WHERE year = 2021
--                         AND month = 7
--                         AND day = 29)));

-- --obtain accomplice seat info from flight--
-- SELECT seat
--     FROM passengers
--     WHERE passport_number =
--     (SELECT passport_number
--         FROM people
--         WHERE phone_number IN
--             (SELECT receiver
--             FROM phone_calls
--             WHERE year = 2021
--             AND month = 7
--             AND day = 28
--             AND duration < 60)
--         AND passport_number IN
--             (SELECT passport_number
--             FROM passengers
--             WHERE flight_id =
--             (SELECT id
--                 FROM flights
--                 WHERE year = 2021
--                 AND month = 7
--                 AND day = 29
--                 AND hour =
--                     (SELECT MIN(hour)
--                         FROM flights
--                             WHERE year = 2021
--                             AND month = 7
--                             AND day = 29))));

-- --obtain info for call in timeframe and with accomplice per interview--
-- SELECT *
--     FROM phone_calls
--     WHERE year = 2021
--     AND month = 7
--     AND day = 28
--     AND duration < 60
--     AND receiver =
--     (SELECT phone_number
--     FROM people
--     WHERE passport_number =
--     (SELECT passport_number
--         FROM people
--         WHERE phone_number IN
--             (SELECT receiver
--             FROM phone_calls
--             WHERE year = 2021
--             AND month = 7
--             AND day = 28
--             AND duration < 60)
--         AND passport_number IN
--             (SELECT passport_number
--             FROM passengers
--             WHERE flight_id =
--             (SELECT id
--                 FROM flights
--                 WHERE year = 2021
--                 AND month = 7
--                 AND day = 29
--                 AND hour =
--                     (SELECT MIN(hour)
--                         FROM flights
--                             WHERE year = 2021
--                             AND month = 7
--                             AND day = 29)))));