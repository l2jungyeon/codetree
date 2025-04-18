# 중고 거래 게시물을 3건 이상 등록한 사용자의 사용자 ID, 닉네임, 전체주소, 전화번호를 조회
# 회원 ID를 기준으로 내림차순

SELECT
    U.USER_ID,
    U.NICKNAME,
    CONCAT(U.CITY, " ", U.STREET_ADDRESS1, " ", U.STREET_ADDRESS2) AS 전체주소,
    CONCAT_WS("-",SUBSTRING(TLNO,1,3), SUBSTRING(TLNO,4,4), SUBSTRING(TLNO,8,4)) AS 전화번호
FROM 
    USED_GOODS_BOARD G
    INNER JOIN USED_GOODS_USER U ON G.WRITER_ID=U.USER_ID
GROUP BY 1
HAVING COUNT(G.BOARD_ID)>=3
ORDER BY 1 DESC