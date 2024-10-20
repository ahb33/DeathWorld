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
<<<<<<< HEAD
            time.sleep(1)  # Add a small sleep to reduce CPU usage
=======
            pass
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582
    except KeyboardInterrupt:
        observer.stop()
    observer.join()

if __name__ == "__main__":
<<<<<<< HEAD
    src_dir = r"C:\Users\PREDATOR\Documents\Unreal Projects\OnlinePlugin\Plugins\MultiplayerPlugin"
    dest_dir = r"C:\Users\PREDATOR\Documents\Unreal Projects\DeathWorld 5.4\Plugins\MultiplayerPlugin"  # Adjusted to expected path
=======
    src_dir = r"C:\Users\User\Documents\Unreal Projects\OnlinePlugin\Plugins\MultiplayerPlugin"
    dest_dir = r"C:\Users\User\Documents\Unreal Projects\DeathWorld\Plugins\MultiplayerPlugin"  # Corrected path
>>>>>>> 0bcdb22c66cd4a7c278cb80e5b52113ddf83a582

    monitor_directory(src_dir, dest_dir)