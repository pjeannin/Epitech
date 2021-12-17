--
-- EPITECH PROJECT, 2021
-- B3 - Func. Prog. Seminar
-- File description:
-- Operation
--

module Operation where

sab :: [Int] -> [Int]
sab [] = []
sab [x] = [x]
sab (x:y:xs) = y:x:xs

sc :: [Int] -> [Int] -> ([Int], [Int])
sc (x:xs) (y:ys) = (sab (x:xs), sab (y:ys))

pab :: [Int] -> [Int] -> ([Int], [Int])
pab [] y = ([], y)
pab (x:xs) [] = (xs, [x])
pab (x:xs) (y:ys) = (xs, x : (y:ys))

rab :: [Int] -> [Int]
rab [] = []
rab [x] = [x]
rab (x:xs) = xs ++ [x]

rr :: [Int] -> [Int] -> ([Int], [Int])
rr x y = (rab x, rab y)

removeLastElem :: [Int] -> [Int]
removeLastElem [] = []
removeLastElem [x] = []
removeLastElem (x:xs) = x : removeLastElem xs

rrab :: [Int] -> [Int]
rrab [] = []
rrab [x] = [x]
rrab (x:xs) = last (x:xs) : removeLastElem (x:xs)

rrr :: [Int] -> [Int] -> ([Int], [Int])
rrr x y = (rrab x, rrab y)