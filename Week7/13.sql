/*List names of co-stars of Kevin Bacon (1958)*/

SELECT DISTINCT people.name
FROM people

JOIN stars
ON people.id = stars.person_id

WHERE stars.movie_id IN
    (SELECT movies.id
    FROM movies

    JOIN stars
    ON movies.id = stars.movie_id

    WHERE stars.person_id =
        (SELECT people.id
        FROM people
        WHERE people.name = "Kevin Bacon"
        AND people.birth = 1958))

AND people.name != "Kevin Bacon";

