SELECT name FROM songs WHERE artist_id = (Select id FROM artists WHERE name = 'Post Malone');
