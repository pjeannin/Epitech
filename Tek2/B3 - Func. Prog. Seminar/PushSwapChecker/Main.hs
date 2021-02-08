--
-- EPITECH PROJECT, 2021
-- B3 - Func. Prog. Seminar
-- File description:
-- Main
--

module Main where
import Operation
import System.Environment
import System.Exit
import Data.Maybe
import Data.List
import Data.Char

containOnlyInt :: [Char] -> Bool
containOnlyInt [] = False
containOnlyInt [x]
        | isDigit x = True
        | otherwise = False
containOnlyInt (x:xs)
        | isDigit x = containOnlyInt xs
        | otherwise = False

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt [x]
        | containOnlyInt [x] = Just (read [x]::Int)
        | otherwise = Nothing
readInt (x:xs)
        | containOnlyInt (x:xs) = Just (read (x:xs)::Int)
        | otherwise = Nothing


checkArgs :: [String] -> Maybe [Int]
checkArgs [] = Nothing
checkArgs [x]
        | isNothing (readInt x) = Nothing
        | otherwise = Just [fromJust (readInt x)]
checkArgs (x:xs)
        | isNothing (readInt x) = Nothing
        | isNothing (checkArgs xs) = Nothing
        | otherwise = Just (fromJust (readInt x) : fromJust (checkArgs xs))

isValidOp :: String -> Maybe String
isValidOp "sa" = Just "sa"
isValidOp "sb" = Just "sb"
isValidOp "sc" = Just "sc"
isValidOp "pa" = Just "pa"
isValidOp "pb" = Just "pb"
isValidOp "ra" = Just "ra"
isValidOp "rb" = Just "rb"
isValidOp "rr" = Just "rr"
isValidOp "rra" = Just "rra"
isValidOp "rrb" = Just "rrb"
isValidOp "rrr" = Just "rrr"
isValidOp x = Nothing

checkOp :: [String] -> Maybe [String]
checkOp [] = Nothing
checkOp [x]
        | isNothing (isValidOp x) = Nothing
        | otherwise = Just [fromJust (isValidOp x)]
checkOp (x:xs)
        | isNothing (isValidOp x) = Nothing
        | isNothing (checkOp xs) = Nothing
        | otherwise = Just (fromJust (isValidOp x) : fromJust (checkOp xs))

splitStringOnSpace :: String -> [String]
splitStringOnSpace x
        | isNothing (elemIndex ' ' x) = [x]
        | otherwise = take (fromJust (elemIndex ' ' x)) x :
        splitStringOnSpace (tail (drop (fromJust (elemIndex ' ' x)) x))

haveToReturn :: Maybe [String] -> Maybe [Int] -> IO Int
haveToReturn Nothing y = exitWith (ExitFailure 84)
haveToReturn x Nothing = exitWith (ExitFailure 84)
haveToReturn x y = return 1

checkIfSorted :: (Ord str) => [str] -> Bool
checkIfSorted [] = True
checkIfSorted [x] = True
checkIfSorted (x:y:xs) = x <= y && checkIfSorted (y:xs)

checkPushSwap :: ([Int], [Int]) -> Bool
checkPushSwap (x, []) = checkIfSorted x
checkPushSwap x = False

applyOpEnd  :: [String] -> [Int] -> [Int] -> ([Int], [Int])
applyOpEnd ("pa":xs) y z = applyOp xs (snd (pab z y)) (fst (pab z y))
applyOpEnd ("pb":xs) y z = uncurry (applyOp xs) (pab y z)
applyOpEnd ("ra":xs) y z = applyOp xs (rab y) z
applyOpEnd ("rb":xs) y z = applyOp xs y (rab z)
applyOpEnd ("rr":xs) y z = uncurry (applyOp xs) (rr y z)
applyOpEnd ("rra":xs) y z = applyOp xs (rrab y) z
applyOpEnd ("rrb":xs) y z = applyOp xs y (rrab z)
applyOpEnd ("rrr":xs) y z = uncurry (applyOp xs) (rrr y z)

applyOpMid :: [String] -> [Int] -> [Int] -> ([Int], [Int])
applyOpMid ["rr"] y z = rr y z
applyOpMid ["rra"] y z = (rrab y, z)
applyOpMid ["rrb"] y z = (y, rrab z)
applyOpMid ["rrr"] y z = rrr z y
applyOpMid ("sa":xs) y z = applyOp xs (sab y) z
applyOpMid ("sb":xs) y z = applyOp xs y (sab z)
applyOpMid ("sc":xs) y z = uncurry (applyOp xs) (sc y z)
applyOpMid x y z = applyOpEnd x y z

applyOp :: [String] -> [Int] -> [Int] -> ([Int], [Int])
applyOp ["sa"] y z = (sab y, z)
applyOp ["sb"] y z = (y, sab z)
applyOp ["sc"] y z = sc z y
applyOp ["pa"] y z = (snd (pab z y), fst (pab z y))
applyOp ["pb"] y z = pab y z
applyOp ["ra"] y z = (rab y, z)
applyOp ["rb"] y z = (y, rab z)
applyOp x y z = applyOpMid x y z

checkIfAlreadySorted :: String -> ([Int], [Int]) -> IO Int
checkIfAlreadySorted "" y
        | checkIfSorted (fst y) = putStr "OK\n" >>
                exitSuccess
        | otherwise = putStr "KO: " >>
                print y >>
                exitSuccess
checkIfAlreadySorted x y = return 1

displayResult :: Bool -> ([Int], [Int]) -> IO ()
displayResult True y = putStrLn "OK"
displayResult False y = putStr "KO: " >>
        print y

main :: IO()
main = do
        x <- getLine
        y <- getArgs
        let args = checkArgs y
        let ops = checkOp (splitStringOnSpace x)
        checkIfAlreadySorted x (fromJust args, [])
        haveToReturn ops args
        let res = applyOp (fromJust ops) (fromJust args) []
        displayResult (checkPushSwap res) res
        exitSuccess