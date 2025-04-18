use serde_json::{Result, Value};
use std::fs::{self, read_to_string};


fn json_to_cpp (json: &Value) -> String {
    let mut cpp: String = 
    "#ifndef BITMAPS\n#define BITMAPS\n#include <Arduino.h>\n#include \"../driver/driver.h\"\n#include \"../graphics/graphics.h\"\n\nnamespace Bitmaps {\n\n".to_owned();

    for bitmap_json in json["bitmaps"].as_array().unwrap() {
        let name = bitmap_json["name"].as_str().unwrap();

        let mut index_array: Vec<u16> = Vec::new();

        let mut max_index: u16 = 0;

        let mut wid = 0;
        let mut hth = 0;

        for row in bitmap_json["bitmap"].as_array().unwrap() {
            hth += 1;
            if wid == 0 {
                wid = row.as_array().unwrap().len() as u16;
            }

            for pixel in row.as_array().unwrap() {
                let i = pixel.as_u64().unwrap() as u16;
                index_array.push(i);
                if i > max_index {
                    max_index = i;
                }
            }
        }

        let mut bit_size = f32::log2((max_index + 1) as f32).ceil() as u8;
        bit_size = if bit_size == 0 {1} else {bit_size};

        let mask: u32 = (0x01 << bit_size) - 1; 

        let mut i_bit: i8 = 0;
        let mut bytes: u32 = 0;

        let mut bitmap: Vec<u8> = Vec::new();

        for pixel in &index_array {

            while i_bit > 7 {
                bitmap.push((bytes & 0xFF) as u8);
                bytes >>= 8;
                i_bit -= 8;
            }

            bytes |= (*pixel as u32 & mask) << i_bit;
            i_bit += bit_size as i8;
        }

        while i_bit > 0 {
            bitmap.push((bytes & 0xFF) as u8);
            bytes >>= 8;
            i_bit -= 8;
        }

        let mut is_palette = false;
        if !bitmap_json.get("palette").is_none() {
            is_palette = true;

            let palette = bitmap_json["palette"].as_array().unwrap();

            cpp.push_str(&format!("\tstatic uint32_t palette_{}[{}] = {{{}}};\n",
                name,
                palette.len(),
                palette.iter().map(|color| color.as_str().unwrap().to_owned()).collect::<Vec<String>>().join(", ")));
        }
        
        cpp.push_str(&format!("\tstatic uint8_t data_{}[{}] = {{{}}};\n",
            name,
            bitmap.len(),
            bitmap.iter().map(|byte| format!("0x{:02x}", byte)).collect::<Vec<String>>().join(", ")));

        cpp.push_str(&format!("\tstatic GFX::Bitmap {} = {{{}, {}, {}, {}, data_{}}};\n\n",
            name,
            wid,
            hth,
            max_index+1,
            if is_palette {format!("palette_{}",name)} else {"NULL".to_owned()},
            name));
    }

    cpp.push_str("}\n\nnamespace Font {\n\n");

    for font_json in json["groups"].as_array().unwrap() {

        let name = font_json["name"].as_str().unwrap();
        let font = font_json["bitmaps"].as_array().unwrap();

        cpp.push_str(&format!("\tstatic GFX::Bitmap* {}[{}] = {{{}}};\n\n",
            name,
            font.len(),
            font.iter().map(|map| format!("&(Bitmaps::{})",map.as_str().unwrap())).collect::<Vec<String>>().join(", ")
        ));

    } 

    cpp.push_str("}\n\n#endif");

    cpp
}


fn main() -> Result<()> {
    let maps_filename = "./bitmaps.json";
    let cpp_filename = "./bitmaps.h";

    let data = read_to_string(maps_filename).unwrap();

    let bitmap_json: Value = serde_json::from_str(&data)?;

    let cpp_str = json_to_cpp(&bitmap_json);

    fs::write(cpp_filename, &cpp_str).expect("Unable to write file");

    Ok(())
}
