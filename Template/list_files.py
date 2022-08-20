import os

name_idx = 4
name_dbg_idx = name_idx + 2
#count = 0
#for root, dirs, files in os.walk("./"):
#    for file in files:
#        if file.endswith(".mid"):
#            count = count + 1
#            split_name = file.split()
#            print("""#{}:{} {}
#+
#
#""".format(count, split_name[7], split_name[8].split(".")[0]))
            #print(os.path.join(root, file))

for root, dirs, files in os.walk("./"):
    for file in files:
        if file.endswith(".mid"):
            split_name = file.split()
            if len(split_name) <= name_idx:
                #print("**** {} ****".format(file))
                continue

            output_name = split_name[name_idx]
            for name in split_name[(name_idx+1):]:
                output_name = output_name + " " + name
            split_name = file.split()
            dbg_name = split_name[0]
            for name in range( 1, name_dbg_idx ):
                dbg_name = dbg_name + " " + split_name[name]
            print("{{ u8\"{}\", u8\"{}.mid TrackParseDebug.txt\", u8\"{}\", 0 }},".format(file, dbg_name.replace('.mid', ''), output_name.replace('.mid', '')))
    break