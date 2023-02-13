use std::io::{stdout, stdin, BufRead, BufWriter, Write};

fn main() {
    let stdin = stdin();
    let stdout = stdout();
    let mut stdin = stdin.lock();
    let mut stdout = BufWriter::new(stdout.lock());

    let mut buf = String::new();
    stdin.read_line(&mut buf).unwrap();

    let n: i32 = buf.trim().parse().unwrap();

    for _i in 0..n {
        buf.clear();
        stdin.read_line(&mut buf).unwrap();
        let iter = buf.trim().split_whitespace();

        for it in iter {
            write!(stdout, "{}", it.chars().rev().collect::<String>()).unwrap();
            write!(stdout, " ").unwrap();
        }
        writeln!(stdout, "").unwrap();
    }
}