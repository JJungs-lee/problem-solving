// #1 - 내가 푼 풀이
// use std::io::{stdout, stdin, BufWriter, BufRead, Write};

// fn main() {
//     let stdin = stdin();
//     let stdout = stdout();
//     let mut stdin = stdin.lock();
//     let mut stdout = BufWriter::new(stdout.lock());

//     let mut buf = String::new();
//     stdin.read_line(&mut buf).unwrap();

//     let n = buf.trim().parse().unwrap();
//     let mut input_ans: Vec<String> = Vec::new();

//     for _i in 0..n {
//         let mut num = String::new();
//         stdin.read_line(&mut num).unwrap();
//         input_ans.push(num.trim().to_string());
//     }

//     let mut cur_idx = 0;
//     let mut stack: Vec<String> = Vec::new();
//     let mut res: Vec<&str> = Vec::new();
//     for i in 1..n + 1 {
//         stack.push(i.to_string());
//         res.push("+");
//         while stack.len() > 0 {
//             match input_ans[cur_idx] == stack[stack.len() -1] {
//                 true => {
//                     stack.pop();
//                     res.push("-");
//                     cur_idx += 1;
//                 },
//                 false => break,
//             }
//         }
//     }

//     match stack.is_empty() {
//         true => {
//             for iter in res {
//                 writeln!(stdout, "{}", iter).unwrap();
//             }
//         },
//         false => writeln!(stdout, "NO").unwrap(),
//     }
// }

// #2 - 다른 사람 풀이 참조 (input쪽 수정)
use std::collections::VecDeque;
use std::io::{stdout, stdin, BufWriter, Write, Read};

fn main() {
    let stdin = stdin();
    let stdout = stdout();
    let mut stdin = stdin.lock();
    let mut stdout = BufWriter::new(stdout.lock());

    let mut input = String::new();
    stdin.read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().map(|i| i.parse::<i32>().unwrap());

    let n = input.next().unwrap();
    let mut v = VecDeque::new();

    for _ in 0..n {
        v.push_back(input.next().unwrap());
    }

    let mut cur_idx = 0;
    let mut stack: Vec<i32> = Vec::new();
    let mut res = String::new();
    for i in 1..n + 1 {
        stack.push(i);
        res.push_str("+\n");
        while stack.len() > 0 {
            match v[cur_idx] == stack[stack.len() -1] {
                true => {
                    stack.pop();
                    res.push_str("-\n");
                    cur_idx += 1;
                },
                false => break,
            }
        }
    }

    match stack.is_empty() {
        true => writeln!(stdout, "{}", res).unwrap(),
        false => writeln!(stdout, "NO").unwrap(),
    }
}
