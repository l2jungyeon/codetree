SELECT HOUR(DATETIME) AS HOUR, COUNT(*)
FROM ANIMAL_OUTS 
GROUP BY 1
HAVING HOUR BETWEEN 9 AND 19
ORDER BY 1 