
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"̿���ż�"NOR);
	set("long",YEL @LONG
    �����ǿ�ӵ��.���ܿ�������һ����Χ���ұڳ��������ھ�ĺۼ�
�Լ���ľͷ�������������ݵ��Ҷ�.�ڵ���������������.ר���˿�ͨ��
ʹ��.
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+4),
		"east" : __DIR__"dong5"+(random(5)+4),
		"south" : __DIR__"dong56",
		"north" : __DIR__"dong58",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong5"+(random(5)+1),
		"south" : __DIR__"dong5"+(random(5)+3),
		"north" : __DIR__"dong58",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong58",
		"west" : __DIR__"dong56",
	]));

         set("objects", ([
              __DIR__"npc/lev7" : 6,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
