
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"众神之失乐园"NOR);
	set("long", HIW @LONG
 这个世界，飘浮在云中,雾中,地板是由发亮的黄金所铺成，四周的墙壁
和天花板上满布著美丽的壁画和精致的石雕。空中悬浮的水晶散发著神秘
的光芒，无可描述飘荡在空中的音乐使这一切如梦如幻。
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong"+(random(18)+3),
		"south" : __DIR__"dong"+(random(13)+3),
                "west" : __DIR__"dong"+(random(8)+3),
                "north" : __DIR__"dong"+(random(3)+3),
	]));
          set("objects", ([
__DIR__"npc/lev3" : random(6),
//             "/clone/box/gboxm" : random(2),
         ]));
if (random(3)==0)
	set("exits", ([
		"eastnorth" : __DIR__"dong"+(random(8)+3),
		"southwest" : __DIR__"dong"+(random(3)+4),
                "westsouth" : __DIR__"dong"+(random(18)+4),
                "northeast" : __DIR__"dong"+(random(13)+4),
	]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
