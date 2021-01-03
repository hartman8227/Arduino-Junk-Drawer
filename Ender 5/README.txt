Project: Ender 5 Mainboard replacement

Aim:
    Extruder driver on the OEM mainboard for the Ender 5 failed. Replacement board from Creality was nonfunctional. Goal is to get the printer back up and running using a MKS Gen L V2.0 mainboard and TMC2130 stepper drivers.
    
Issues:
    // - Mainboard failure
    - MKS board is not a drop in replacement and will not fix in existing board location. Design new casing?
    //- Etruder fan not functioning. Changed fin assignment in firmware. still need to upload and test.
    //	- This has been tested and it is working.
    //- Stepper Motors not moving. M122 reports ALL LOW - FIXED
    - End Stops not registering - FIXED
    - Massive over-extrusion
        - Fixed by adjusting extrusion multiplier in slicer to 0.48. WHY IS THIS SO LOW
            - TRY REINITILIZING EEPROM WITH M502
    - Parts peeling up from print surface and bad bed adheasion.
            - ENABLED MANUAL MESH BED LEVELING IN SOURCE. REFLASH FIRMWARE TO TRY OUT
    
    - Display shows blue screen but nothing else.
/* Shopping List:
//    - MKS Gen L V2.0    // In Stock
//    = TMC2130 x 4       // In Stock
//    - Heatsinks         // IN Stock
	
