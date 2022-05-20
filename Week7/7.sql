/*List movies, with ratings, released in 2010 in descending order by rating then title*/
SELECT movies.title, ratings.rating
FROM ratings
JOIN movies
ON ratings.movie_id = movies.id
WHERE movies.year = 2010 AND ratings.rating IS NOT NULL
ORDER BY rating DESC, title;