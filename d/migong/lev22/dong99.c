#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"光暗之神殿"NOR);
	set("long", HIW @LONG
 这个世界，飘浮在云中,雾中,地板是由发亮的黄金所铺成，四周的墙壁
和天花板上满布著美丽的壁画和精致的石雕。空中悬浮的水晶散发著神秘
的光芒，无可描述飘荡在空中的音乐使这一切如梦如幻。
LONG NOR);
	set("exits", ([
		"down" : __DIR__"dong98",
		"up" : __DIR__"dong100",
                	]));
set("no_npc",1);
       set("objects", ([
              __DIR__"npc/bossz1" : 1,
             __DIR__"npc/bossz2": 1,
            "/d/migong/lev14/npc/boss" : 2,
            "/d/migong/lev15/npc/boss" : 2,
            	            	            	            	
"/clone/box/gboxm" : 2,
                ]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");

    if(me->is_busy())
        return notify_fail("你现在正忙。\n");

	if (1)
	{

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你想拐卖人口？\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}
