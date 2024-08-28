import os
import shutil
import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

class PluginSyncHandler(FileSystemEventHandler):
    def __init__(self, src_dir, dest_dir):
        self.src_dir = src_dir
        self.dest_dir = dest_dir
        self.ignore_extensions = ['.temp']
        self.ignore_folders = ['Intermediate', 'Binaries']
        self.last_synced = {}
        self.sync_delay = 1  # 1-second delay to avoid syncing incomplete files

        self.initial_sync()

    def initial_sync(self):
        for root, dirs, files in os.walk(self.src_dir):
            dirs[:] = [d for d in dirs if d not in self.ignore_folders]
            for file in files:
                src_file = os.path.join(root, file)
                if any(src_file.endswith(ext) for ext in self.ignore_extensions):
                    continue
                self.sync_files(src_file)

    def on_modified(self, event):
        if not event.is_directory:
            time.sleep(self.sync_delay)  # Wait before syncing to avoid active files
            self.sync_files(event.src_path)

    def on_created(self, event):
        if not event.is_directory:
            time.sleep(self.sync_delay)  # Wait before syncing to avoid active files
            self.sync_files(event.src_path)

    def sync_files(self, src_path):
        if any(src_path.endswith(ext) for ext in self.ignore_extensions):
            return

        if any(folder in src_path for folder in self.ignore_folders):
            return

        now = time.time()
        if src_path in self.last_synced and now - self.last_synced[src_path] < 1:
            return
        self.last_synced[src_path] = now

        relative_path = os.path.relpath(src_path, self.src_dir)
        dest_path = os.path.join(self.dest_dir, relative_path)

        os.makedirs(os.path.dirname(dest_path), exist_ok=True)

        shutil.copy2(src_path, dest_path)
        print(f"Synced: {src_path} to {dest_path}")

def monitor_directory(src_dir, dest_dir):
    event_handler = PluginSyncHandler(src_dir, dest_dir)
    observer = Observer()
    observer.schedule(event_handler, path=src_dir, recursive=True)
    observer.start()
    print(f"Monitoring {src_dir} for changes...")

    try:
        while True:
            pass
    except KeyboardInterrupt:
        observer.stop()
    observer.join()

if __name__ == "__main__":
    src_dir = r"C:\Users\User\Documents\Unreal Projects\OnlinePlugin\Plugins\MultiplayerPlugin"
    dest_dir = r"C:\Users\User\Documents\Unreal Projects\DeathWorld\Plugins\MultiplayerPlugin"  # Corrected path

    monitor_directory(src_dir, dest_dir)