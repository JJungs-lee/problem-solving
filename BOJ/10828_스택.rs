use std::io::stdin;

fn main() {
    let mut n = String::new();
    stdin().read_line(&mut n).expect("Failed to read line");

    let n: usize = n.trim().parse().expect("");
    let mut stack: Vec<String> = Vec::new();

    for _i in 0..n  {
        let mut line = String::new();
        stdin().read_line(&mut line).expect("Failed to read line");

        let words: Vec<&str> = line.trim().split(' ').collect();

        match words[0] {
            "push" => stack.push(words[1].to_string()),
            "pop" => {
                if stack.is_empty() {
                    println!("-1");
                } else {
                    println!("{}",  stack[stack.len() - 1]);
                    stack.pop();
                }
            },
            "size" => println!("{}", stack.len()),
            "empty" => println!("{}", (stack.is_empty()) as i32),
            "top" => {
                if stack.is_empty() {
                    println!("-1");
                } else {
                    println!("{}", stack[stack.len() - 1]);
                }
            },
            _ => continue,
        }
    }
}
