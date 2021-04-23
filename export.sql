--------------------------------------------------------
--  Fichier créé - vendredi-avril-23-2021   
--------------------------------------------------------
DROP TABLE "BORIS"."SALAIRE";
DROP TABLE "BORIS"."PRIME";
--------------------------------------------------------
--  DDL for Table SALAIRE
--------------------------------------------------------

  CREATE TABLE "BORIS"."SALAIRE" 
   (	"NUMS" NUMBER, 
	"MONTANT" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PRIME
--------------------------------------------------------

  CREATE TABLE "BORIS"."PRIME" 
   (	"NOM" VARCHAR2(20 BYTE), 
	"NUMP" NUMBER, 
	"VALEUR" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into BORIS.SALAIRE
SET DEFINE OFF;
Insert into BORIS.SALAIRE (NUMS,MONTANT) values ('1','30000');
Insert into BORIS.SALAIRE (NUMS,MONTANT) values ('345','345');
Insert into BORIS.SALAIRE (NUMS,MONTANT) values ('123','2345');
REM INSERTING into BORIS.PRIME
SET DEFINE OFF;
Insert into BORIS.PRIME (NOM,NUMP,VALEUR) values ('prime','1','1000');
Insert into BORIS.PRIME (NOM,NUMP,VALEUR) values (null,'2','10000');
