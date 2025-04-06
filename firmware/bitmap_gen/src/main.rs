use std::{collections::HashSet, fs::read_to_string};
use std::fs;

#[derive(Debug)]
struct Bitmap {
    name: String,
    bitmap: Vec<u8>,
    palette: Vec<u32>,
    wid: u8,
    hth: u8,
}

impl Default for Bitmap{
    fn default () -> Bitmap {
        Bitmap {name: "".to_owned(), bitmap: Vec::new(), palette: Vec::new(), wid: 0, hth: 0}
    }
}

enum MapStates {
    Name,
    Palette,
    Map, 
}

impl Bitmap {
    

    fn to_cpp_string (&self) -> String {
        if self.palette.len() <= 2 {
            format!("//{}\nuint8_t bitmap_{}_data[{}] = {{{}}};\nBitmap bitmap_{} = {{{},{},bitmap_{}_data}};\n\n", 
            self.name, 
            self.name,
            (self.wid * self.hth + 7) / 8,
            self.to_byte_str(),
            self.name, 
            self.wid, 
            self.hth, 
            self.name).to_owned()
        } else {
            format!("//{}\nCRGB* bitmap_{}_data[{}] = {{{}}};\nBitmap bitmap_{} = {{{},{},bitmap_{}_data}};\n\n", 
            self.name, 
            self.name,
            self.wid * self.hth,
            self.bitmap.iter().map(|val| format!("CRGB(0x{:06x})", self.palette[*val as usize])).collect::<Vec<String>>().join(","),
            self.name, 
            self.wid, 
            self.hth, 
            self.name).to_owned()
        }
    } 

    fn to_byte_str(&self) -> String {
        let mut bytes_str = "".to_owned();
        let mut byte: u8 = 0;
        let mut i: i32 = 0;
        for bit in &self.bitmap {
            if *bit != 0 {
                byte |= 1_u8 << i;
            }   
            if i == 7 {
                bytes_str.push_str(&format!("0x{:02x},", byte));
                byte = 0;
                i = 0;
            }
            i += 1;
        }
        if i != 0 {
            bytes_str.push_str(&format!("0x{:02x},", byte));
        }
        bytes_str[0..bytes_str.len()-1].to_owned()
    }

    fn from_file(filename: &str) -> (Vec<Bitmap>, HashSet<String>) {
        let mut bitmaps: Vec<Bitmap> = Vec::new();
        let mut map_count = 0;

        let mut names_set: HashSet<String> = HashSet::new();
        
        let mut m_state = MapStates::Name;
        let mut height = 0;
        let lines = read_to_string(filename).unwrap();
        for line in lines.lines() {
            match m_state {
                MapStates::Name => {
                    m_state = MapStates::Palette;
                    bitmaps.push(Bitmap::default());
                    bitmaps[map_count].name = line.to_owned();
                }
                MapStates::Palette => {
                    m_state = MapStates::Map;
                    if line.chars().nth(0) == Some('[') {
                        bitmaps[map_count].palette = line[1..line.len()-1].split(",").map(|s| u32::from_str_radix(s.trim_start_matches(" ").trim_start_matches("0x"), 16).unwrap()).collect();
                    } else {
                        height += 1;
                        let mut data: Vec<u8> = line.split(",").map(|s| s.parse::<u8>().unwrap()).collect();
                        bitmaps[map_count].wid = data.len() as u8;
                        bitmaps[map_count].bitmap.append(&mut data);
                    }
                }
                MapStates::Map => {
                    if line == "" {
                        m_state = MapStates::Name;
                        bitmaps[map_count].hth = height;
                        names_set.insert(bitmaps[map_count].name.clone());
                        map_count += 1;
                        height = 0;
                    } else {
                        height += 1;
                        let mut data: Vec<u8> = line.split(",").map(|s| s.parse::<u8>().unwrap()).collect();
                        bitmaps[map_count].wid = data.len() as u8;
                        bitmaps[map_count].bitmap.append(&mut data);
                    }
                }
            } 
        }
        bitmaps[map_count].hth = height;
        names_set.insert(bitmaps[map_count].name.clone());

        (bitmaps, names_set)
    }
}

struct BitmapGroup;

enum GroupStates {
    Name,
    Mapping,
}

impl BitmapGroup {

    fn from_file(filename: &str, names: HashSet<String>) -> String{

        let mut group_str = "".to_owned();
        let mut state = GroupStates::Name;
        let lines = read_to_string(filename).unwrap();

        let mut name: String = "".to_owned();

        for line in lines.lines() {
            match state {
                GroupStates::Name => {
                    state = GroupStates::Mapping;
                    name = line.to_owned();
                }
                GroupStates::Mapping => {
                    state = GroupStates::Name;
                    let mapping: Vec<&str> = line[1..line.len()-1].split(",").map(|s| if names.contains(s.trim_start_matches(" ")) {s.trim_start_matches(" ")} else {"NULL"}).collect();
                    group_str.push_str(&format!("//{name}\nBitmap {name}[{}] = {{{}}};\n\n", mapping.len(), mapping.iter().map(|val| format!("bitmap_{}", val)).collect::<Vec<String>>().join(",")));
                }
            }
        }
        group_str
    }
}

fn main() {
    let maps_filename = "./maps.txt";
    let map_groups_filename = "./map_groups.txt";
    let cpp_filename = "./bitmaps.h";

    let (bitmaps, names) = Bitmap::from_file(maps_filename);

    let mut cpp_str = "".to_owned();

    cpp_str.push_str("#include <Arduino.h>\n#include <FastLED.h>\n#include \"Sign_GFX.h\"\n\n");

    
    for bitmap in &bitmaps {
        cpp_str.push_str(&bitmap.to_cpp_string());
    }

    cpp_str.push_str("//Groups\n\n");
    cpp_str.push_str(&BitmapGroup::from_file(map_groups_filename, names));

    fs::write(cpp_filename, &cpp_str).expect("Unable to write file");
}