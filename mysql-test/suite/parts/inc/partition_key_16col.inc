--disable_query_log
# DATA DIRECTORY
eval SET @data_dir = 'DATA DIRECTORY =
''/tmp''';
let $data_directory = `select @data_dir`;

#INDEX DIRECTORY
eval SET @indx_dir = 'INDEX DIRECTORY =
''/tmp''';
let $index_directory = `select @indx_dir`;
--enable_query_log

eval create table t1 (a date not null, b varchar(50) not null, c varchar(50) not null, d enum('m', 'w') not null, e int not null, f decimal (18,2) not null, g bigint not null, h tinyint not null, a1 date not null, b1 varchar(50) not null, c1 varchar(50) not null, d1 enum('m', 'w') not null, e1 int not null, f1 decimal (18,2) not null, g1 bigint not null, h1 tinyint not null, i char(255), primary key(a,b,c,d,e,f,g,h,a1,b1,c1,d1,e1,f1,g1,h1)) engine=$engine 
partition by key(a,b,c,d,e,f,g,h,a1,b1,c1,d1,e1,f1,g1,h1) (
partition pa1 $data_directory $index_directory max_rows=20 min_rows=2,
partition pa2 $data_directory $index_directory max_rows=30 min_rows=3,
partition pa3 $data_directory $index_directory max_rows=30 min_rows=4,
partition pa4 $data_directory $index_directory max_rows=40 min_rows=2);
show create table t1;
insert into t1 values 
('1975-01-01', 'abcde', 'abcde','m', 1234, 123.45, 32412341234, 113,'1975-01-01', 'abcde', 'abcde','m', 1234, 123.45, 32412341234, 113, 'tbhth nrzh ztfghgfh fzh ftzhj fztjh'), 
('1983-12-31', 'cdef', 'srtbvsr', 'w', 45634, 13452.56, 3452346456, 127,'1983-12-31', 'cdef', 'srtbvsr', 'w', 45634, 13452.56, 3452346456, 127, 'liuugbzvdmrlti b itiortudirtfgtibm dfi'), 
('1980-10-14', 'fgbbd', 'dtzndtz', 'w', 67856, 5463354.67, 3567845333, 124,'1980-10-14', 'fgbbd', 'dtzndtz', 'w', 67856, 5463354.67, 3567845333, 124, 'd,f söierugsig msireg siug ei5ggth lrutluitgzeöjrtnb.rkjthuekuhzrkuthgjdnffjmbr'),
('2000-06-15', 'jukg','zikhuk','m', 45675, 6465754.13, 435242623462, 18, '2000-06-15', 'jukg','zikhuk','m', 45675, 6465754.13, 435242623462, 18, 'pib mdotkbm.m');
select * from t1;
select * from t1 where a<19851231;
drop table t1;