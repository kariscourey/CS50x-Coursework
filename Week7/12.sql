/*List titles of movies with Johnny Depp and Helena Bonham Carter*/

SELECT movies.title
FROM movies

JOIN stars
ON movies.id = stars.movie_id
JOIN people
ON stars.person_id = people.id

WHERE people.name = "Johnny Depp"
AND movies.id IN
    (SELECT stars.movie_id
    FROM stars
    WHERE stars.person_id =
        (SELECT people.id
        FROM people
        WHERE people.name = "Helena Bonham Carter"));
