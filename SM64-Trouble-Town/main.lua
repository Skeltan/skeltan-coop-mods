-- name: Super Mario 64 Trouble Town
-- description: This rom hack has been created by Nobbie. \n\nThere is 30 Stars to collect in 6 different levels !\n\nRom hack ported by Skeltan
-- incompatible: romhack

gLevelValues.exitCastleLevel = LEVEL_CASTLE_GROUNDS
gLevelValues.exitCastleWarpNode = 0x40

----------------
-- fix camera --
----------------

camera_set_use_course_specific_settings(false)

-----------
-- music --
-----------

smlua_audio_utils_replace_sequence(0x0B, 0x14, 100, '0B_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x0D, 0x16, 100, '0D_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x0E, 0x17, 100, '0E_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x0F, 0x18, 100, '0F_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x01, 0x22, 100, '01_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x1B, 0x14, 100, '1B_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x1C, 0x20, 100, '1C_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x1D, 0x1E, 100, '1D_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x1E, 0x1B, 100, '1E_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x1F, 0x1A, 100, '1F_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x02, 0x11, 100, '02_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x03, 0x25, 100, '03_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x04, 0x25, 100, '04_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x10, 0x12, 100, '10_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x12, 0x1F, 100, '12_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x14, 0x1A, 100, '14_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x15, 0x0E, 100, '15_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x16, 0x1B, 100, '16_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x17, 0x1A, 100, '17_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x20, 0x23, 100, '20_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x21, 0x25, 100, '21_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x23, 0x25, 100, '23_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x25, 0x25, 100, '25_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x26, 0x25, 100, '26_Seq_super-mario-64-trouble-town_custom')
smlua_audio_utils_replace_sequence(0x29, 0x15, 100, '29_Seq_super-mario-64-trouble-town_custom')

