- 데이터 조회 (between(사이에), distinct(중복제거 칼럼명 전에 작성)
select col from table;
select col from table where 조건;
select col from table where 조건 order by column asc; or desc;
select col from table where 조건 order by column asc limit 개수; 하면 개수만큼 출력
select col from table where 조건 between 00 and 00;
select distinct col from table;
select col from table where 조건 in (00, 00);
select col from table where 조건 like '%단어%';

 WHERE절에서 연산자의 왼쪽은 가동하지 않는다. 컬럼을 가공하면 색인을 사용할 수 없다.
        WHERE 컬럼 * 3 < 10 말고 WHERE 컬럼 < 10 / 3 을 사용하자


- 데이터 입력
insert into table (col1, col2, col3) VALUES (값1, 값2, 값3);

- 데이터 수정
update table set col = 변경할 값;
이 뒤에도 where 사용 가능
