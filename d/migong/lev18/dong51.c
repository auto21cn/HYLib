
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"炭坑遗迹"NOR);
	set("long",YEL @LONG
    这里是矿坑的深处.你能看到的是一个周围的岩壁充满著被挖掘的痕迹
以及用木头架设著以免塌陷的岩洞.在地上有铁轨铺设著.专供运矿车通行
使用.
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong16",
		"east" : __DIR__"dong52",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(3)+4),
		"north" : __DIR__"dong1"+(random(3)+4),
		"west" : __DIR__"dong52",
                "east" : __DIR__"dong16",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong16",
		"west" : __DIR__"dong52",
	]));

        set("objects", ([
              __DIR__"npc/lev2" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

