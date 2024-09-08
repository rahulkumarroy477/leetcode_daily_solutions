# Write your MySQL query statement below
SELECT w1.id
FROM Weather w1
JOIN Weather w2 ON DATE(w1.recordDate) = DATE(w2.recordDate) + INTERVAL 1 DAY
WHERE w1.temperature > w2.temperature;