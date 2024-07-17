# Write your MySQL query statement below
(
    SELECT name AS results
    FROM MovieRating JOIN Users ON MovieRating.user_id = Users.user_id
    GROUP BY MovieRating.user_id 
    ORDER BY COUNT(*) DESC, name ASC LIMIT 1
)
UNION ALL
(
    SELECT title AS results
    FROM Movies JOIN MovieRating ON Movies.movie_id = MovieRating.movie_id
    WHERE SUBSTR(created_at, 1, 7) = '2020-02'
    GROUP BY Movies.movie_id ORDER BY AVG(rating) DESC, title ASC LIMIT 1
);
-- union all for duplicate values