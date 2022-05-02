/*List titles of five highest ratest movies with Chadwick Boseman*/
SELECT movies.title
FROM movies
JOIN stars
ON movies.id = stars.movie_id
JOIN ratings
ON movies.id = ratings.movie_id
JOIN people
ON stars.person_id = people.id
WHERE stars.person_id = "Chadwick Boseman"
ORDER BY ratings.rating;