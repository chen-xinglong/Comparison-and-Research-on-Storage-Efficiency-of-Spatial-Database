-- 创建表 插入数据 compression --
use geo_test;
SET GLOBAL innodb_file_per_table=1;
drop table if exists poly200;
drop table if exists poly400;
drop table if exists poly600;
drop table if exists poly800;
drop table if exists poly1000;
drop table if exists poly2000;
drop table if exists poly4000;
drop table if exists poly6000;
drop table if exists poly8000;
create table poly200(geom geometry) ENGINE=InnoDB,ROW_FORMAT= COMPRESSED KEY_BLOCK_SIZE=8  ; 
create table poly400(geom geometry) ENGINE=InnoDB ROW_FORMAT= COMPRESSED KEY_BLOCK_SIZE=8  ; 
create table poly600(geom geometry) ENGINE=InnoDB ROW_FORMAT= COMPRESSED KEY_BLOCK_SIZE=8  ; 
create table poly800(geom geometry) ENGINE=InnoDB ROW_FORMAT= COMPRESSED KEY_BLOCK_SIZE=8  ; 
create table poly1000(geom geometry) ENGINE=InnoDB ROW_FORMAT= COMPRESSED KEY_BLOCK_SIZE=8  ; 
create table poly2000(geom geometry) ENGINE=InnoDB ROW_FORMAT= COMPRESSED KEY_BLOCK_SIZE=8  ; 
create table poly4000(geom geometry) ENGINE=InnoDB ROW_FORMAT= COMPRESSED KEY_BLOCK_SIZE=8  ; 
create table poly6000(geom geometry) ENGINE=InnoDB ROW_FORMAT= COMPRESSED KEY_BLOCK_SIZE=8  ; 
create table poly8000(geom geometry) ENGINE=InnoDB ROW_FORMAT= COMPRESSED KEY_BLOCK_SIZE=8  ; 
load data infile "E:\\dataChange\\CountPoints\\CountPoints\\200.txt" replace into table poly200 lines terminated by'\r\n'
(@c1)
set geom=st_geomfromtext(@c1);
load data infile "E:\\dataChange\\CountPoints\\CountPoints\\400.txt" replace into table poly400 lines terminated by'\r\n'
(@c2)
set geom=st_geomfromtext(@c2);
load data infile "E:\\dataChange\\CountPoints\\CountPoints\\600.txt" replace into table poly600 lines terminated by'\r\n'
(@c3)
set geom=st_geomfromtext(@c3);
load data infile "E:\\dataChange\\CountPoints\\CountPoints\\800.txt" replace into table poly800 lines terminated by'\r\n'
(@c4)
set geom=st_geomfromtext(@c4);
load data infile "E:\\dataChange\\CountPoints\\CountPoints\\1000.txt" replace into table poly1000 lines terminated by'\r\n'
(@c5)
set geom=st_geomfromtext(@c5);
load data infile "E:\\dataChange\\CountPoints\\CountPoints\\2000.txt" replace into table poly2000 lines terminated by'\r\n'
(@c6)
set geom=st_geomfromtext(@c6);
load data infile "E:\\dataChange\\CountPoints\\CountPoints\\4000.txt" replace into table poly4000 lines terminated by'\r\n'
(@c7)
set geom=st_geomfromtext(@c7);
load data infile "E:\\dataChange\\CountPoints\\CountPoints\\6000.txt" replace into table poly6000 lines terminated by'\r\n'
(@c8)
set geom=st_geomfromtext(@c8);
load data infile "E:\\dataChange\\CountPoints\\CountPoints\\8000.txt" replace into table poly8000 lines terminated by'\r\n'
(@c9)
set geom=st_geomfromtext(@c9);