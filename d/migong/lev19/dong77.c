#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"�ɴ�֮�ż�"NOR);
	set("long", CYN @LONG
   ��˵����һ�ҽ��������ŵķɴ�����ħ�������������˵��ǰ��
һ��������յĳ��У���֪ʲôʱ������������˵�ڵĵط���ϡ��
���ĵ��Ǽװ�����ӣ������������أ����е�ɱ��Խ��ԽŨ�ˡ�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+4),
		"east" : __DIR__"dong7"+(random(4)+5),
		"south" : __DIR__"dong7"+(random(4)+4),
		"north" : __DIR__"dong7"+(random(4)+5),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong78",
		"west" : __DIR__"dong7"+(random(4)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(4)+4),
		"north" : __DIR__"dong78",
	]));
         set("objects", ([
              __DIR__"npc/lev7" : 1,
              __DIR__"npc/lev6" : 2,
              __DIR__"npc/player" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}