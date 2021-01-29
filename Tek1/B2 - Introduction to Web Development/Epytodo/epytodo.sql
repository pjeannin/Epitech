CREATE TABLE `epytodo`.`user` (
    `user_id` INT NOT NULL AUTO_INCREMENT,
    `username` VARCHAR(32) NOT NULL,
    `password` VARCHAR(64) NOT NULL,
PRIMARY KEY (`user_id`));

CREATE TABLE `epytodo`.`task` (
    `task_id` INT NOT NULL AUTO_INCREMENT,
    `title` VARCHAR(45) NOT NULL,
    `begin` DATETIME NULL,
    `end` DATETIME NULL,
    `status` ENUM ('not started','in progress','done') NOT NULL DEFAULT 'not started',
PRIMARY KEY (`task_id`));

CREATE TABLE `epytodo`.`user_has_task` (
    `id` INT NOT NULL AUTO_INCREMENT,
    `fk_user_id` INT NULL,
    `fk_task_id` INT NULL,
PRIMARY KEY (`id`));