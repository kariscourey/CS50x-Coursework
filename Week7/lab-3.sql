--Lists names of top 5 longest songs dec order of length--
SELECT name
    FROM songs
    ORDER BY duration_ms DESC
    LIMIT 5;