#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"
#include "game/level_update.h"
#include "levels/scripts.h"
#include "actors/common1.h"
#include "make_const_nonconst.h"

#include "areas/1/custom.model.inc.h"

#include "levels/ccm/header.h"
#include "levels/ttc/header.h"

extern u8 _ccm_segment_ESegmentRomStart[];
extern u8 _ccm_segment_ESegmentRomEnd[];

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _ttc_segment_7SegmentRomStart, _ttc_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _ttcSegmentRomStart, _ttcSegmentRomEnd),
	LOAD_RAW(0x0E, _ccm_segment_ESegmentRomStart, _ccm_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _bits_skybox_mio0SegmentRomStart, _bits_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group2_mio0SegmentRomStart, _group2_mio0SegmentRomEnd),
	LOAD_RAW(12, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd),
	LOAD_MIO0(6, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd),
	LOAD_RAW(13, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_CUBE,     ttc_geo_000240),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_PRISM,    ttc_geo_000258),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_PENDULUM,          ttc_geo_000270),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_LARGE_TREADMILL,   ttc_geo_000288),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_SMALL_TREADMILL,   ttc_geo_0002A8),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_PUSH_BLOCK,        ttc_geo_0002C8),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_HEXAGON,  ttc_geo_0002E0),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_TRIANGLE, ttc_geo_0002F8),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_PIT_BLOCK,         ttc_geo_000310),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_PIT_BLOCK_UNUSED,  ttc_geo_000328),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_ELEVATOR_PLATFORM, ttc_geo_000340),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_CLOCK_HAND,        ttc_geo_000358),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_SPINNER,           ttc_geo_000370),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_SMALL_GEAR,        ttc_geo_000388),
	    LOAD_MODEL_FROM_GEO(MODEL_TTC_LARGE_GEAR,        ttc_geo_0003A0),
	// Unspecified Models
	LOAD_MODEL_FROM_GEO(22,  warp_pipe_geo),
	LOAD_MODEL_FROM_GEO(23,  bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(24,  spiky_tree_geo),
	LOAD_MODEL_FROM_GEO(25,  snow_tree_geo),
	LOAD_MODEL_FROM_GEO(27,  palm_tree_geo),
	LOAD_MODEL_FROM_GEO(31,  metal_door_geo),
	LOAD_MODEL_FROM_GEO(32,  hazy_maze_door_geo),
	LOAD_MODEL_FROM_GEO(34,  castle_door_0_star_geo),
	LOAD_MODEL_FROM_GEO(35,  castle_door_1_star_geo),
	LOAD_MODEL_FROM_GEO(36,  castle_door_3_stars_geo),
	LOAD_MODEL_FROM_GEO(37,  key_door_geo),
	LOAD_MODEL_FROM_GEO(38,  castle_door_geo),
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_3),
	JUMP_LINK(script_func_global_15),
	JUMP_LINK(local_area_ccm_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_ccm_1_[] = {
	AREA(1, Geo_ccm_1_0x1434330),
	TERRAIN(col_ccm_1_0xe030720),
	SET_BACKGROUND_MUSIC(0, 38),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ccm_1_),
	JUMP_LINK(local_warps_ccm_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ccm_1_[] = {
	OBJECT_WITH_ACTS(0, 22, 0, 10010, 0, 180, 0, 0x430000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(86, -874, 422, 2708, 0, 0, 0, 0x0,  bhvSmallBully, 31),
	OBJECT_WITH_ACTS(86, 239, 422, 3960, 0, 0, 0, 0x0,  bhvSmallBully, 31),
	OBJECT_WITH_ACTS(86, 2927, -195, 298, 0, 0, 0, 0x0,  bhvSmallBully, 31),
	OBJECT_WITH_ACTS(86, -1260, 0, -97, 0, 0, 0, 0x0,  bhvSmallBully, 31),
	OBJECT_WITH_ACTS(87, 116, 5986, -2414, 0, 0, 0, 0x0,  bhvBigBully, 31),
	OBJECT_WITH_ACTS(0, -1390, -64, -4786, 0, 0, 0, 0x0,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, 4076, 107, 1749, 0, 180, 0, 0x0,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, 2071, 107, -1009, 0, 0, 0, 0x0,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, -3867, 363, -477, 0, 0, 0, 0x0,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(122, -7217, 240, -2601, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -5456, 234, -5895, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 8185, 536, -1998, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -3404, 2336, 4278, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, 979, 0, -354, 0, 0, 0, 0x5000000,  bhvHiddenRedCoinStar, 31),
	OBJECT_WITH_ACTS(215, -3493, 363, -3700, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -4343, 363, 495, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 4896, -6, 1251, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 3753, -64, -3605, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 526, 3023, 4697, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -10, 1999, -565, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -331, 2972, 758, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -3184, 0, 3821, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(140, -3199, 272, 930, 0, 0, 0, 0x0,  bhvBlueCoinSwitch, 31),
	OBJECT_WITH_ACTS(118, -2972, 272, 1220, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -3392, 272, 1223, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -3226, 272, 2120, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -2907, 272, 2317, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(118, -3243, 272, 2504, 0, 0, 0, 0x0,  bhvHiddenBlueCoin, 31),
	OBJECT_WITH_ACTS(0, 3106, -64, -3229, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -312, 3775, 3974, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 536, 3775, 3985, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 1388, 3775, 4005, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 5125, 1186, 1242, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -5, 1999, -566, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -257, 366, 3285, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -6, 422, 913, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1391, -64, -3717, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3369, 363, 106, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 4528, 1186, 609, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3176, 0, 3810, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 15, 422, 5945, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 10, 4, 318, 0, 0, 20, 0,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 10, 4, 16, 0, 0, 20, 1,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_ccm_1_[] = {
	WARP_NODE(67, 16, 3, 67, 0),
	WARP_NODE(240, 16, 3, 56, 0),
	WARP_NODE(241, 16, 3, 106, 0),
	RETURN()
};