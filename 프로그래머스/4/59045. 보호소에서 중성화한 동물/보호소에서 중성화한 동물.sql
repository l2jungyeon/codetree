#보호소에 들어올 당시에는 중성화1되지 않았지만, 보호소를 나갈 당시에는 중성화된 동물의 아이디와 생물 종, 이름을 조회
#아이디 순서

#Intact Male->Neutered Male
#Intact Female->Spayed Female

SELECT I.ANIMAL_ID, I.ANIMAL_TYPE, I.NAME
FROM ANIMAL_INS I 
    INNER JOIN ANIMAL_OUTS O ON I.ANIMAL_ID=O.ANIMAL_ID
WHERE I.SEX_UPON_INTAKE LIKE("Intact%") 
        AND (O.SEX_UPON_OUTCOME LIKE("Neutered%") 
             OR O.SEX_UPON_OUTCOME LIKE("Spayed%") )
ORDER BY I.ANIMAL_ID