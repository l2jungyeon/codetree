SELECT E.ID, COUNT(C.ID) AS CHILD_COUNT
FROM
    ECOLI_DATA E
    LEFT JOIN ECOLI_DATA C ON E.ID=C.PARENT_ID
GROUP BY 1
ORDER BY 1