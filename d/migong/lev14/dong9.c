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
		"south" : __DIR__"dong85",
		"north" : __DIR__"dong92",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}