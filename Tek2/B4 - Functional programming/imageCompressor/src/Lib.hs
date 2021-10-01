module Lib where

import Text.Read ( readMaybe )
import Data.Maybe
import System.Exit ( ExitCode(ExitFailure), exitWith )

data Conf = Conf Int Float String

getFilepath :: Conf -> String
getFilepath (Conf _ _ filePath) = filePath

newConf :: Conf
newConf = Conf (-1) (-1) ""

getOpts :: Conf -> [String] -> Maybe Conf
getOpts (Conf n l f) ("-n":xs:xxs)
    | isNothing(readMaybe xs :: Maybe Int) = Nothing
    | (read xs :: Int) < 0 = Nothing
    | otherwise = getOpts (Conf (read xs :: Int) l f) xxs
getOpts (Conf n l f) ("-l":xs:xxs)
    | isNothing(readMaybe xs :: Maybe Float) = Nothing
    | (read xs :: Float) < 0 = Nothing
    | otherwise = getOpts (Conf n (read xs :: Float) f) xxs
getOpts (Conf n l f) ("-f":xs:xxs) = getOpts (Conf n l xs) xxs
getOpts (Conf n l f) (x:xs) = Nothing
getOpts (Conf n l f) _ = Just (Conf n l f)

printConf :: Conf -> IO()
printConf (Conf n l f) = print n >> print l >> print f

testConf :: Maybe Conf -> IO()
testConf (Just (Conf _ _ "")) = putStr "USAGE: ./imageCompressor -n N -l L" >>
    putStr " -f F\n\n\tN\tnumber of colors in the final image\n\tL\tconverge" >>
    putStr "nce limit\n\tF\tpath to the file containing the colors of the pi" >>
    putStrLn "xels" >> exitWith (ExitFailure 84)
testConf Nothing = putStr "USAGE: ./imageCompressor -n N -l L" >>
    putStr " -f F\n\n\tN\tnumber of colors in the final image\n\tL\tconverge" >>
    putStr "nce limit\n\tF\tpath to the file containing the colors of the pi" >>
    putStrLn "xels" >> exitWith (ExitFailure 84)
testConf (Just (Conf x y _))
    | x <= 0 = putStr "USAGE: ./imageCompressor -n N -l L" >>
    putStr " -f F\n\n\tN\tnumber of colors in the final image\n\tL\tconverge" >>
    putStr "nce limit\n\tF\tpath to the file containing the colors of the pi" >>
    putStrLn "xels" >> exitWith (ExitFailure 84)
    | y <= 0 = putStr "USAGE: ./imageCompressor -n N -l L" >>
    putStr " -f F\n\n\tN\tnumber of colors in the final image\n\tL\tconverge" >>
    putStr "nce limit\n\tF\tpath to the file containing the colors of the pi" >>
    putStrLn "xels" >> exitWith (ExitFailure 84)
testConf _ = putStr ""

split :: (Eq a) => a -> [a] -> [[a]]
split _ [] = []
split separator ys = f : split separator (dropSeparator separator rest)
    where (f, rest) = break (== separator) ys

dropSeparator :: Eq a => a ->  [a] -> [a]
dropSeparator _ [] = []
dropSeparator separator (x:xs) = if x == separator then xs else x:xs

getfst :: (Int, Int, Int) -> Int
getfst (x, _, _) = x

getsnd :: (Int, Int, Int) -> Int
getsnd (_, x, _) = x

getthird :: (Int, Int, Int) -> Int
getthird (_, _, x) = x


createTuple :: String -> (Int, Int)
createTuple x = (read (tail (head (split ',' x))) :: Int, read
    (init (split ',' x !! 1)) :: Int)

createTriple :: String -> (Int, Int, Int)
createTriple x = (read (tail (head (split ',' x))) :: Int, read
    (split ',' x !! 1) :: Int, read (init (split ',' x !! 2)) :: Int)

getInfos :: String -> ((Int, Int), (Int, Int, Int))
getInfos x = (createTuple (head (words x)), createTriple (words x !! 1))

processText :: [String] -> [((Int, Int), (Int, Int, Int))]
processText [x] = [getInfos x]
processText (x:xs) = getInfos x : processText xs

emptyTab :: [((Int, Int), (Int, Int, Int))]
emptyTab = []

isSorted :: [((Int, Int), (Int, Int, Int))] -> Bool
isSorted [x, xs]
    | distance (snd x) (0, 0, 0) > distance (snd xs) (0, 0, 0) = False
    | otherwise = True
isSorted (x:xs:xxs)
    | distance (snd x) (0, 0, 0) > distance (snd xs) (0, 0, 0) = False
    | otherwise = isSorted (xs:xxs)

pixelSorting :: [((Int, Int), (Int, Int, Int))] -> [((Int, Int), (Int, Int, Int))]
pixelSorting [x, xs]
    | distance (snd x) (0, 0, 0) > distance (snd xs) (0, 0, 0) = [xs, x]
    | otherwise = [x, xs]
pixelSorting (x:xs:xxs)
    | distance (snd x) (0, 0, 0) > distance (snd xs) (0, 0, 0) = xs : pixelSorting (x:xxs)
    | otherwise = x : pixelSorting (xs:xxs)

sortPixels :: [((Int, Int), (Int, Int, Int))] -> [((Int, Int), (Int, Int, Int))]
sortPixels x
    | isSorted x = x
    | otherwise = sortPixels (pixelSorting x)

createBase :: Conf -> Int -> [((Int, Int), (Int, Int, Int))] ->
    [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
createBase (Conf 1 _ _) n t = [(((getfst (snd (head t))),
        (getsnd (snd (head t))), (getthird (snd (head t)))), emptyTab)]
createBase (Conf x y z) n t
    | n < x = (((getfst (snd (t !! ((length t) `div` x * n)))), (getsnd (snd
        (t !! ((length t) `div` x * n)))), (getthird (snd (t !! ((length t)
        `div` x * n))))), emptyTab) : createBase (Conf x y z) (n + 1) t
    | otherwise = [(((getfst (snd (t !! ((length t) `div` x * n)))),
        (getsnd (snd (t !! ((length t) `div` x * n)))), (getthird (snd (t !!
        ((length t) `div` x * n))))), emptyTab)]

distance :: (Int, Int, Int) -> (Int, Int, Int) -> Float
distance (x1, x2, x3) (y1, y2, y3) = sqrt((fromIntegral y1 - fromIntegral x1)
    ^ 2 +(fromIntegral y2 - fromIntegral x2) ^ 2 + (fromIntegral y3 -
    fromIntegral x3) ^ 2)

loop :: [((Int, Int), (Int, Int, Int))] -> (Int, Int, Int)
    -> (Int, Int, Int) -> (Int, Int, Int)
loop [x] y z
    | z == (-1, -1, -1) = snd x
    | distance (snd x) y < distance z y = snd x
    | otherwise = z
loop (x:xs) y z
    | z == (-1, -1, -1) = loop xs y (snd x)
    | distance (snd x) y < distance z y = loop xs y (snd x)
    | otherwise = loop xs y z

closetBetwenPoint :: [((Int, Int), (Int, Int, Int))] -> (Int, Int, Int)
    -> (Int, Int, Int)
closetBetwenPoint x y = loop x y (-1, -1, -1)

smallest :: [((Int, Int), (Int, Int, Int))] -> (Int, Int, Int)
smallest x = closetBetwenPoint x (0, 0, 0)

biggest :: [((Int, Int), (Int, Int, Int))] -> (Int, Int, Int)
biggest x = closetBetwenPoint x (255, 255, 255)

compute :: ((Int, Int), (Int, Int, Int)) ->
    [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] ->
    (Int, Int, Int) -> (Int, Int, Int)
compute x [y] z
    | (-1, -1, -1) == z = fst y
    | distance (snd x) (fst y) < distance (snd x) z = fst y
    | otherwise = z
compute x (y:ys) z
    | (-1, -1, -1) == z = compute x ys (fst y)
    | distance (snd x) (fst y) < distance (snd x) z = compute x ys (fst y)
    | otherwise = compute x ys z

closest :: ((Int, Int), (Int, Int, Int)) -> [((Int, Int, Int),
    [((Int, Int), (Int, Int, Int))])] -> (Int, Int, Int)
closest x y = compute x y (-1, -1, -1)

getIndex :: (Int, Int, Int) ->
    [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> Int -> Int
getIndex x y n
    | length y == n + 1 = n
    | x == fst (y !! n) = n
    | otherwise = getIndex x y (n + 1)

updateTab :: [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] ->
    ((Int, Int), (Int, Int, Int)) -> Int ->
    [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
updateTab [x] y z
    | z == 0 = [(fst x, snd x ++ [y])]
    | otherwise = [x]
updateTab (x:xs) y z
    | z == 0 = (fst x, snd x ++ [y]) : updateTab xs y (z - 1)
    | otherwise = x : updateTab xs y (z - 1)

updateColor :: (Int, Int, Int) -> [((Int, Int), (Int, Int, Int))] ->
    Int -> (Int, Int, Int)
updateColor _ [] _ = (0, 0, 0)
updateColor x [y] n = ((getfst x + getfst (snd y)) `div` n, (getsnd x + getsnd
    (snd y)) `div` n, (getthird x + getthird (snd y)) `div` n)
updateColor x (y:ys) n = updateColor (getfst x + getfst (snd y), getsnd x +
    getsnd (snd y), getthird x + getthird (snd y)) ys (n + 1)

updateAverageColor :: [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] ->
    [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
updateAverageColor [x] = [(updateColor (0, 0, 0) (snd x) 1, snd x)]
updateAverageColor (x:xs) = (updateColor (0, 0, 0) (snd x) 1, snd x) :
    updateAverageColor xs

sort :: [((Int, Int), (Int, Int, Int))] ->
    [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] ->
    [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
sort [x] y = updateTab y x (getIndex (closest x y) y 0)
sort (x:xs) y = sort xs (updateTab y x (getIndex (closest x y) y 0))

doItAgain :: Conf -> [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] ->
    [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> Bool
doItAgain (Conf n l p) [x] [y]
    | l > distance (fst x) (fst y) = False
    | otherwise = True
doItAgain (Conf n l p) (x:xs) (y:ys)
    | l > distance (fst x) (fst y) = False
    | otherwise = doItAgain (Conf n l p) xs ys

process :: Conf -> [((Int, Int), (Int, Int, Int))] ->
    [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] ->
    [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])]
process (Conf n l p) x y
    | doItAgain (Conf n l p) (sort x y) y =
        process (Conf n l p) x (updateAverageColor (sort x y))
    | otherwise = updateAverageColor (sort x y)

printTab :: [((Int, Int), (Int, Int, Int))] -> IO()
printTab [] = putStrLn ""
printTab [x] = putStr "(" >> putStr (show (fst (fst x))) >> putStr "," >> putStr (show (snd (fst x))) >> putStr ") " >> print (snd x)
printTab (x:xs) = putStr "(" >> putStr (show (fst (fst x))) >> putStr "," >> putStr (show (snd (fst x))) >> putStr ") " >> print (snd x) >> printTab xs

displayResults :: [((Int, Int, Int), [((Int, Int), (Int, Int, Int))])] -> IO()
displayResults [x] = putStrLn "--" >> print (fst x) >> putStrLn "-" >>
    printTab (snd x)
displayResults (x:xs) = putStrLn "--" >> print (fst x) >> putStrLn "-" >>
    printTab (snd x) >> displayResults xs