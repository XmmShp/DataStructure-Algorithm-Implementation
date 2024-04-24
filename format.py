import os


def main():
    format_file = []
    print('start format')
    if os.system('clang-format --version'):
        raise SystemError('you have not clang-format in your $path')
    for filepath, dirname, filenames in os.walk('.'):
        for filename in filenames:
            if filename.find('.cpp') != -1:
                format_file.append(os.path.join(filepath, filename))
    print(format_file)
    for file in format_file:
        os.system(f'clang-format -i {file}')
        print(f'format {file}')
    print('format success.')


if __name__ == '__main__':
    main()
