// Room: d/kyoto/yusuogate
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��������");
set("long", @LONG
̧ͷһ�������Ÿ������ƣ��·�Ҫ����ѹ����������͸�Ų��ɿ��ܵ���
�ϣ�������Ǿ������������ţ������������Ļʹ��������������£�������
��仯�����˶����������׺���Ϊˮ����ȥ��ɽ�����ơ��ĸп���
LONG );
set("exits",  ([
        "east"  : __DIR__"hongqiao",
        "west"  : __DIR__"yuqiao",
        "south"  : __DIR__"jinqiao1",
      ]));
        setup();
        replace_program(ROOM);
}