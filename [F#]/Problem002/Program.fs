open System
open System.Numerics

#light

let sTicks = DateTime.UtcNow.Ticks

let problem002 =
    let fibs =
        (1,1) |> Seq.unfold
            (fun (n0,n1) ->
                if n0 <= 4000000 then
                    Some (n0, (n1, n0 + n1))
                else
                    None)
    fibs |> Seq.fold
        (fun acc x ->
            if x % 2 = 0 then
                acc + x
            else
                acc) 0

let eTicks = DateTime.UtcNow.Ticks

printfn "Problem 002: answer is %A" problem002
printfn "Execution time: %d" (eTicks-sTicks)


Console.ReadKey()