// Room: d/kyoto/chashi
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "����");
set("long", @LONG
������һ����ң�װ��Ĳ��㿼���������������ӣ��б�Թ����ά��
������ʧ�ĸ������ۣ�Ҳ����̸��Ļĩʱ�ڸ��ɳ������͵Ĵ�˵��������
����ľ��Ǳ��˳�Ϊ���ε�ի����糴彣�ĵĴ��档��˵�ε�ի��Ļĩ��
���Ķ��ǵĶ���׫���鳤������֮�ǡ�ի��һһս�ͷ������Աߵ�С���
LONG );
set("exits",  ([
        "north"  : __DIR__"qianbending3",
        "south"  : __DIR__"xiaoxiang2",
      ]));
        setup();
        replace_program(ROOM);
}