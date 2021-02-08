myElem :: Eq a => a -> [a] -> Bool
myElem t [] = False
myElem t [x]
    | t == x = True
    | otherwise = False
myElem t (x:xs)
    | t == x = True
    | otherwise = myElem t xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [a] -> Int -> Maybe a
safeNth (x:_) 0 = Just x
safeNth (x:xs) y
    | y < 0 = Nothing
    | y >= length (x:xs) = Nothing
    | otherwise = safeNth xs (y - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just x) = fmap (+x) (Just 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup x [] = Nothing
myLookup x [y]
    | x == fst y = Just (snd y)
    | otherwise = Nothing
myLookup x (y:ys)
    | x == fst y = Just (snd y)
    | otherwise  = myLookup x ys

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo f Nothing _ = Nothing
maybeDo f _ Nothing = Nothing
maybeDo f (Just x) (Just y) = Just (f x y)

containOnlyInt :: [Char] -> Bool
containOnlyInt [] = False
containOnlyInt [x]
    | x >= '0' && x <= '9' = True
    | otherwise = False
containOnlyInt (x:xs)
    | x >= '0' && x <= '9' = containOnlyInt xs
    | otherwise = False

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt [x]
    | containOnlyInt [x] = Just (read [x]::Int)
    | otherwise = Nothing
readInt (x:xs)
    | containOnlyInt (x:xs) = Just (read (x:xs)::Int)
    | otherwise = Nothing

getLineLength :: IO Int
getLineLength = length <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength s =  putStrLn s >>
        return (length s)

getFirstLastLine :: Int -> String
getFirstLastLine 1 = "+\n"
getFirstLastLine x = "-" ++ getFirstLastLine(x - 1)

getMidLine :: Int -> String
getMidLine 1 = "|\n"
getMidLine x = " " ++ getMidLine(x - 1)

createMid :: Int -> Int -> String
createMid x y
    | x > 3 = "|" ++ getMidLine (2 * y - 1) ++ createMid (x - 1) y
    | otherwise = "|" ++ getMidLine (2 * y - 1)

printBox :: Int -> IO()
printBox 1 = putStr "++\n"
printBox 2 = putStr "+--+\n+--+\n"
printBox x
    | x <= 0 = putStr ""
    | otherwise =  putStr ("+" ++ getFirstLastLine (2 * x - 1)) >>
        putStr (createMid x x) >>
        putStr ("+" ++ getFirstLastLine (2 * x - 1))

liftM2 :: Monad m => (a -> b -> c) -> m a -> m b -> m c
liftM2 f m1 m2 = do
    val1 <- m1
    val2 <- m2
    return $ f val1 val2

concatLines :: Int -> IO String
concatLines 1 = getLine
concatLines x
    | x <= 0 = return ""
    | otherwise = liftM2 (++) getLine (concatLines (x - 1))

getInt :: IO (Maybe Int)
getInt = getLine >>= \s -> return (readInt s)