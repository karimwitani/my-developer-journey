
# DATABASES

- [DATABASES](#databases)
  - [Databases](#databases-1)
    - [What is an index? How is it different from a primary key?](#what-is-an-index-how-is-it-different-from-a-primary-key)
    - [What is the difference between a clustered and unclustered index?](#what-is-the-difference-between-a-clustered-and-unclustered-index)
  - [SQL](#sql)
  - [MySQL](#mysql)
    - [*What is the memory usage of various datatypes?*](#what-is-the-memory-usage-of-various-datatypes)
  - [SQLALCHEMY](#sqlalchemy)
    - [SqlAlchemy - General](#sqlalchemy---general)
      - [*How to connect to databases?*](#how-to-connect-to-databases)
      - [*How to run queries in sqlachemy?*](#how-to-run-queries-in-sqlachemy)
      - [*How to work with differnt SQL flavors/dialects*](#how-to-work-with-differnt-sql-flavorsdialects)
    - [SqlAlchemy - ORM](#sqlalchemy---orm)
      - [*What is the ORM and how is it useful?*](#what-is-the-orm-and-how-is-it-useful)
      - [*What are datamodels and how are they used?*](#what-are-datamodels-and-how-are-they-used)
      - [*How to define a datamodel?*](#how-to-define-a-datamodel)
      - [*How to define a foreign key in a datamodel?*](#how-to-define-a-foreign-key-in-a-datamodel)
    - [*What is the difference between backref and back\_populates?*](#what-is-the-difference-between-backref-and-back_populates)
  - [LIQUIBASE](#liquibase)
    - [Overview](#overview)
    - [Quickstart](#quickstart)
      - [*How do you install liquibase?*](#how-do-you-install-liquibase)
      - [*How do you run liquibase migrations?*](#how-do-you-run-liquibase-migrations)
  - [FLYWAY](#flyway)
  - [References](#references)

---

## Databases

### What is an index? How is it different from a primary key?

### What is the difference between a clustered and unclustered index?

---

## SQL

---

## MySQL

---

### *What is the memory usage of various datatypes?*

MEMORY tables use a fixed-length row-storage format. Variable-length types such as VARCHAR are stored using a fixed length.
[MySQL memory storage documentation,](https://dev.mysql.com/doc/refman/8.0/en/memory-storage-engine.html)

## SQLALCHEMY

---

### SqlAlchemy - General  

#### *How to connect to databases?*

#### *How to run queries in sqlachemy?*

#### *How to work with differnt SQL flavors/dialects*

### SqlAlchemy - ORM  

#### *What is the ORM and how is it useful?*

#### *What are datamodels and how are they used?*

#### *How to define a datamodel?*

#### *How to define a foreign key in a datamodel?*

- [SO - Use of relationship and ForeignKey modules in SQLAlchemy](https://stackoverflow.com/questions/34958687/use-of-relationship-and-foreignkey-modules-in-sqlalchemy)

### *What is the difference between backref and back_populates?*

- [SO - Why I need both relationship and foreign key for Many to One relationship?](https://stackoverflow.com/questions/54694826/why-i-need-both-relationship-and-foreign-key-for-many-to-one-relationship)
- [SO - Concepts of backref and back_populate in SQLalchemy?](https://stackoverflow.com/questions/51335298/concepts-of-backref-and-back-populate-in-sqlalchemy)

## LIQUIBASE

---

### Overview

Liquibase is a version control software for databases, similar to what git is to code.

### Quickstart

#### *How do you install liquibase?*

#### *How do you run liquibase migrations?*

## FLYWAY

---

## References

---

- SQL Shack: a pretty nice blog with docs and tutorials : [sqlshack](https://www.sqlshack.com/)
