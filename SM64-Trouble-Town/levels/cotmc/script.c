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

#include "levels/cotmc/header.h"
#include "levels/bbh/header.h"

extern u8 _cotmc_segment_ESegmentRomStart[];
extern u8 _cotmc_segment_ESegmentRomEnd[];

const LevelScript level_cotmc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _cotmc_segment_ESegmentRomStart, _cotmc_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _bitfs_skybox_mio0SegmentRomStart, _bitfs_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd),
	LOAD_RAW(12, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd),
	LOAD_MIO0(6, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd),
	LOAD_RAW(13, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR,           haunted_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP,         geo_bbh_0005B0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM,      geo_bbh_0005E0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF,       geo_bbh_000610),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR,          geo_bbh_000628),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND,         geo_bbh_000640),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB,            geo_bbh_000658),
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
	// LOAD_MODEL_FROM_DL(84, 0x05002e00, 4),
	// LOAD_MODEL_FROM_DL(86, 0x05003120, 4),
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_9),
	JUMP_LINK(script_func_global_15),
	JUMP_LINK(local_area_cotmc_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_cotmc_1_[] = {
	AREA(1, Geo_cotmc_1_0x14bed10),
	TERRAIN(col_cotmc_1_0xe007420),
	SET_BACKGROUND_MUSIC(0, 0),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_cotmc_1_),
	JUMP_LINK(local_warps_cotmc_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_cotmc_1_[] = {
	OBJECT_WITH_ACTS(0, 3043, 247, -257, 0, -90, 0, 0x3b0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(85, -2964, 247, -262, 0, 0, 0, 0x10000,  bhvCapSwitch, 31),
	OBJECT_WITH_ACTS(137, -2700, 611, -71, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, -511, 3659, -393, 0, 0, 0, 0x0,  bhvStar, 31),
	//OBJECT_WITH_ACTS(0, 30, 5, 12, 0, 0, 20, 20,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 30, 5, 238, 0, 0, 20, 21,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 30, 5, 12, 0, 0, 20, 22,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 30, 5, 24, 0, 0, 20, 23,  RM_Scroll_Texture, 31),
	//OBJECT_WITH_ACTS(0, 30, 5, 12, 0, 0, 20, 24,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_cotmc_1_[] = {
	WARP_NODE(59, 24, 1, 59, 0),
	WARP_NODE(240, 16, 1, 56, 0),
	WARP_NODE(241, 24, 1, 111, 0),
	RETURN()
};