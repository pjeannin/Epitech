module Lib where

import Text.Read ( readMaybe )
import Data.Maybe
import System.Exit ( ExitCode(ExitFailure), exitWith )

type Rules = Cell -> Cell -> Cell -> Cell
type Start = Int
type Lines = Int
type Window = Int
type Move = Int
type Cell = Char
type BeforeWindow = [Cell]
type InWindow = [Cell]
type AfterWindow = [Cell]
type Line = (BeforeWindow, InWindow, AfterWindow)

data Conf = Conf (Maybe Rules) Start (Maybe Lines) Window Move

defaultConf :: Conf
defaultConf = Conf Nothing 0 Nothing 80 0

getRules :: Conf -> Maybe Rules
getRules (Conf rules _ _ _ _) = rules

getStart :: Conf -> Start
getStart (Conf _ start _ _ _) = start

getLines :: Conf -> Maybe Lines
getLines (Conf _ _ lines _ _) = lines

getWindow :: Conf -> Window
getWindow (Conf _ _ _ window _) = window

getMove :: Conf -> Move
getMove (Conf _ _ _ _ move) = move

getBeforeWindow :: Line -> [Cell]
getBeforeWindow (before, _, _) = before

getWin :: Line -> [Cell]
getWin (_, win, _) = win

getAfterWindow :: Line -> [Cell]
getAfterWindow (_, _, after) = after

getOpts :: Conf -> [String] -> Maybe Conf
getOpts (Conf rules start lines window move) ("./wolfram":xs) = getOpts
    (Conf rules start lines window move) xs
getOpts (Conf rules start lines window move) ("--rule":xs:xxs)
    | isNothing(readMaybe xs :: Maybe Int) = Nothing
    | (read xs :: Int) == 30 = getOpts
        (Conf (Just rule30) start lines window move) xxs
    | (read xs :: Int) == 90 = getOpts
        (Conf (Just rule90) start lines window move) xxs
    | (read xs :: Int) == 110 = getOpts
        (Conf (Just rule110) start lines window move) xxs
    | otherwise = Nothing
getOpts (Conf rules start lines window move) ("--start":xs:xxs)
    | isNothing(readMaybe xs :: Maybe Int) = Nothing
    | (read xs :: Int) < 0 = Nothing
    | otherwise = getOpts (Conf rules ((read xs :: Int)) lines window move) xxs
getOpts (Conf rules start lines window move) ("--lines":xs:xxs)
    | isNothing(readMaybe xs :: Maybe Int) = Nothing
    | (read xs :: Int) < 0 = Nothing
    | otherwise = getOpts
        (Conf rules start (Just (read xs :: Int)) window move) xxs
getOpts (Conf rules start lines window move) ("--window":xs:xxs)
    | isNothing(readMaybe xs :: Maybe Int) = Nothing
    | (read xs :: Int) < 0 = Nothing
    | otherwise = getOpts (Conf rules start lines (read xs :: Int) move) xxs
getOpts (Conf rules start lines window move) ("--move":xs:xxs)
    | isNothing(readMaybe xs :: Maybe Int) = Nothing
    | otherwise = getOpts (Conf rules start lines window (read xs :: Int)) xxs
getOpts (Conf rules start lines window move) (x:xs) = Nothing
getOpts (Conf rules start lines window move) _ =
        Just (Conf rules start lines window move)

testConf :: Maybe Conf -> IO()
testConf (Just (Conf Nothing start lines window move)) =
    putStrLn "Invalid Arguments\n\nUSAGE\n \
    \t./wolfram --rule[30 | 90 | 110] [other Args]"
    >> exitWith (ExitFailure 84)
testConf Nothing =
    putStrLn "Invalid Arguments\n\nUSAGE\n \
    \t./wolfram --rule[30 | 90 | 110] [other Args]"
    >> exitWith (ExitFailure 84)
testConf _ = putStr ""

rule30 :: Cell -> Cell -> Cell -> Cell
rule30 '*' '*' '*' = ' '
rule30 '*' '*' ' ' = ' '
rule30 '*' ' ' '*' = ' '
rule30 '*' ' ' ' ' = '*'
rule30 ' ' '*' '*' = '*'
rule30 ' ' ' ' '*' = '*'
rule30 ' ' '*' ' ' = '*'
rule30 ' ' ' ' ' ' = ' '
rule30 _ _ _ = ' '

rule90 :: Cell -> Cell -> Cell -> Cell
rule90 '*' '*' '*' = ' '
rule90 '*' '*' ' ' = '*'
rule90 '*' ' ' '*' = ' '
rule90 '*' ' ' ' ' = '*'
rule90 ' ' '*' '*' = '*'
rule90 ' ' '*' ' ' = ' '
rule90 ' ' ' ' '*' = '*'
rule90 ' ' ' ' ' ' = ' '
rule90 _ _ _ = ' '

rule110 :: Cell -> Cell -> Cell -> Cell
rule110 '*' '*' '*' = ' '
rule110 '*' '*' ' ' = '*'
rule110 '*' ' ' '*' = '*'
rule110 '*' ' ' ' ' = ' '
rule110 ' ' '*' '*' = '*'
rule110 ' ' '*' ' ' = '*'
rule110 ' ' ' ' '*' = '*'
rule110 ' ' ' ' ' ' = ' '
rule110 _ _ _ = ' '

createFirstLine :: Conf -> Int -> Line -> Line
createFirstLine (Conf rule start lines window move) x (bef, win, af)
    | x == window = (bef, win, af)
    | x == window `div` 2 + move = createFirstLine
        (Conf rule start lines window move) (x + 1) (bef, win ++ ['*'], af)
    | otherwise = createFirstLine
        (Conf rule start lines window move) (x + 1) (bef, win ++ [' '], af)

newBefore :: Rules -> [Cell] -> Int -> [Cell] -> Cell -> [Cell]
newBefore rule [x] 0 y z = ' ' : [rule ' ' x z]
newBefore rule x 0 y z =
        newBefore rule x 1 (' ' : [rule ' ' (x !! 0) (x !! 1)]) z
newBefore rule x i y z
    | length x == i + 1 = y ++ [rule (x !! (i - 1)) (x !! i) z]
    | otherwise = newBefore rule x (i + 1) (y ++ [rule (x !! (i - 1))
        (x !! i) (x !! (i + 1))]) z

newWin :: Rules -> [Cell] -> Int -> [Cell] -> Cell -> Cell -> [Cell]
newWin rule [x] 0 y z a = [rule z x a]
newWin rule x 0 y z a = newWin rule x 1 [rule z (x !! 0) (x !! 1)] z a
newWin rule x i y z a
    | length x == i + 1 = y ++ [rule (x !! (i - 1)) (x !! i) a]
    | otherwise = newWin rule x (i + 1) (y ++ [rule (x !! (i - 1))
        (x !! i) (x !! (i + 1))]) z a

newAfter :: Rules -> [Cell] -> Int -> [Cell] -> Cell -> [Cell]
newAfter rule [x] 0 y z = rule z x ' ' : [' ']
newAfter rule x 0 y z = newAfter rule x 1 [rule z (x !! 0) (x !! 1)] z
newAfter rule x i y z
    | length x == i + 1 = y ++ [rule (x !! (i - 1)) (x !! i) ' '] ++ [' ']
    | otherwise = newAfter rule x (i + 1) (y ++ [rule (x !! (i - 1)) (x !! i)
        (x !! (i + 1))]) z

update :: Conf -> Line -> Line
update (Conf rule start lines window move) (before, win, after) =
        (newBefore (fromJust rule) before 0 [] (win !! 0), newWin
        (fromJust rule) win 0 [] (last before) (after !! 0),
        newAfter (fromJust rule) after 0 [] (last win))

liveDisplay :: Line -> Conf -> Int -> IO()
liveDisplay x (Conf rule start Nothing window move) y
    | y >= start = printLine x >> liveDisplay (update (Conf rule start Nothing
        window move) x) (Conf rule start Nothing window move) (y + 1)
    | otherwise = liveDisplay (update (Conf rule start Nothing window move) x)
        (Conf rule start Nothing window move) (y + 1)
liveDisplay x (Conf rule start line window move) y
    | y >= start && y  + 1 < fromJust line + start = printLine x >> liveDisplay
        (update (Conf rule start line window move) x)
        (Conf rule start line window move) (y + 1)
    | y + 1 < fromJust line + start = liveDisplay (update (Conf rule start line
        window move) x) (Conf rule start line window move) (y + 1)
    | otherwise = printLine x

compute :: [Line] -> Conf ->Int -> [Line]
compute x (Conf rule start lines window move) y
    | y == fromJust lines + start = x
    | otherwise = compute (x ++ [update (Conf rule start lines window move)
        (last x)]) (Conf rule start lines window move) (y + 1)

printLine :: Line -> IO()
printLine (_, win, after) = putStrLn win

displayLines :: [Line] -> Int -> Int -> IO()
displayLines [x] y z = printLine x
displayLines (x:xs) y z
    | y > z = printLine x >> displayLines xs (y + 1) z
    | otherwise = displayLines xs (y + 1) z