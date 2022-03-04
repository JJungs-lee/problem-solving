use std::io;

static mut ans: i32 = 0;

fn z(y: i32, x: i32, r: i32, c: i32, size: i32) -> () {
    if y == r && x == c {
        unsafe {
            println!("{}", ans);
            return;
        }
    }

    if y <= r && r < y + size && x <= c && c < x + size {
        let div = size / 2;
        z(y, x, r, c,div);
        z(y, x + div, r, c,div);
        z(y + div , x, r, c,div);
        z(y +div, x + div, r, c,div);
    } else {
        unsafe {
            ans += size * size;
        }
    }
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);

    let input: Vec<i32> = line.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();

    z(0, 0, input[1], input[2], 1 << input[0]);
}
