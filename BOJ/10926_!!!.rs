use std::io::{stdout, stdin, BufRead, BufWriter, Write};

fn main() {
    let stdin = stdin();
    let stdout = stdout();
    let mut stdin = stdin.lock();
    let mut stdout = BufWriter::new(stdout.lock());
    
    let mut str = String::new();
    stdin.read_line(&mut str).unwrap();

    writeln!(stdout, "{}??!", str.trim()).unwrap();
}
