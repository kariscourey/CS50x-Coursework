/*List titles of movies in alphabetical order released in or after 2018*/
SELECT title
FROM movies
WHERE year >= 2018
ORDER BY title;