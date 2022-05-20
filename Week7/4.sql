/*Report number of movies with 10.0 rating*/
SELECT COUNT(movie_id)
FROM ratings
WHERE rating = 10.0;