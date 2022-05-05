--Lists songs by Post Malone--
SELECT name
    FROM songs
    WHERE songs.artist_id =
    (SELECT id
        FROM artists
        WHERE artists.name = "Post Malone");