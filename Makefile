TARGET = main
SRC = src/main.c
CC = sdcc
FLAGS = --model-large --std-sdcc99
OUTDIR = output

# 完整编译流程
all: $(OUTDIR) $(TARGET).hex

# 创建输出目录
$(OUTDIR):
	mkdir -p $(OUTDIR)

# 从 .ihx 生成 .hex
$(TARGET).hex: $(OUTDIR)/$(TARGET).ihx
	packihx $< > $@

# 生成中间 .ihx 文件到输出目录
$(OUTDIR)/$(TARGET).ihx: $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(OUTDIR)/$(@F)

clean:
	rm -rf $(OUTDIR)
	rm -f *.hex
	@echo "已清理所有构建产物"
