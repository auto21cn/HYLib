#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"���Ҷ�"NOR);
	set("long", RED @LONG
    �����ҽ�����ɢ�������������˴�����������һЩǰ��
δ���ľ޴������������߶��š� 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong01",
		"south" : __DIR__"dong100",
                	]));
       set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             "/d/migong/obj/npc1" : random(2),             
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}