use std::time::{Duration, Instant};
use rand::Rng;
const SIZE:usize = 10000;
fn create_array() -> [i32; SIZE] {
    let mut arr: [i32; SIZE] = [0; SIZE];
    let mut rng = rand::thread_rng();
    for i in 0..arr.len() {
        arr[i] = rng.gen();
    }
    arr
}

//Bubble Sort
pub fn bubble_sort(mut myarray: [i32; SIZE]) {
    let n = myarray.len();
    for _ in 1.. n {
        for j in 0.. n-1 {
            if myarray[j+1] < myarray[j] {
                myarray.swap(j+1, j);
            }
        }
    }
}

//Insertion Sort
pub fn insertion_sort(mut myarray: [i32; SIZE]) {
    let (mut i, len) = (1, myarray.len());
    while i < len {
        let mut j = i;
        while j > 0 && myarray[j-1] > myarray[j] {
            myarray.swap(j, j-1);
            j = j - 1;
        }
        i = i + 1;
    }
}

//Selection Sort
pub fn selection_sort(mut myarray: [i32; SIZE]) {
    let (mut i, len) = (0, myarray.len());
    while i < len {
        let (mut j, mut cur_min) = (i + 1, i);
        while j < len {
            if myarray[j] < myarray[cur_min] {
                cur_min = j;
            }
            j = j + 1;
        }
        myarray.swap(i, cur_min);
        i = i + 1;
    }
}

//Shell Sort
pub fn shell_sort(mut myarray: [i32; SIZE]) {
    let len = myarray.len();
    let mut gap = len as i32 / 2;

    while gap > 0 {
        for i in gap..len as i32 {
            let temp = myarray[i as usize];
            let mut j = i;

            while j >= gap && myarray[j as usize - gap as usize] > temp {
                myarray.swap(j as usize, j as usize - gap as usize);
                j -= gap;
            }

            myarray[j as usize] = temp;
        }
        gap /= 2;
    }
}

//Heap Sort
pub fn heap_sort(myarray: &mut [i32]) {
    if myarray.len() <= 1 {
        return;
    }

    let last_parent = (myarray.len() - 2) / 2;
    for i in (0..=last_parent).rev() {
        move_down(myarray, i);
    }

    for end in (1..myarray.len()).rev() {
        myarray.swap(0, end);
        move_down(&mut myarray[..end], 0);
    }
}

fn move_down(myarray: &mut [i32], mut root: usize) {
    let last = myarray.len() - 1;
    loop {
        let left = 2 * root + 1;
        if left > last {
            break;
        }
        let right = left + 1;
        let child = if right <= last && myarray[right] > myarray[left] {
            right
        } else {
            left
        };

        if myarray[child] > myarray[root] {
            myarray.swap(root, child);
        }
        root = child;
    }
}


fn main() {
    let arr = create_array();

    let bubble = arr;
    let mut start = Instant::now();
    bubble_sort(bubble);
    let mut duration = start.elapsed();
    println!("Time elapsed in bubble sort is: {:?} sec for {:?}", duration.as_secs_f32() , arr.len());
    
    let insertion = arr;
    start = Instant::now();
    insertion_sort(insertion);
    duration = start.elapsed();
    println!("Time elapsed in insertion sort is: {:?} sec for {:?}", duration.as_secs_f32(), arr.len());
    
    let selection = arr;
    start = Instant::now();
    selection_sort(selection);
    duration = start.elapsed();
    println!("Time elapsed in selection sort is: {:?} sec for {:?}", duration.as_secs_f32(), arr.len());

    let shell = arr;
    start = Instant::now();
    shell_sort(shell);
    duration = start.elapsed();
    println!("Time elapsed in shell sort is: {:?} sec for {:?}", duration.as_secs_f32(), arr.len());

    let mut heap_arr= arr;
    start = Instant::now();
    heap_sort(&mut heap_arr);
    duration = start.elapsed();
    println!("Time elapsed in heap sort is: {:?} sec for {:?}", duration.as_secs_f32(), arr.len());

}
