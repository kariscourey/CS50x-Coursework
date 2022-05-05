--Lists average energy of songs by Drake--
SELECT AVG(energy)
    FROM songs
    WHERE songs.artist_id =
    (SELECT id
        FROM artists
        WHERE artists.name = "Drake");