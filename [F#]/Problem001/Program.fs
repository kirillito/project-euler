open System

let check n = if ((n%3 = 0) || (n%5 = 0)) then n else 0

let rec problem001 n = if (n > 0) then check (n) + problem001 (n-1) else 0

let answer = problem001 (999)

printfn "Problem 001: answer is %d" answer

Console.ReadKey()