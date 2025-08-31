terraform {
  required_providers {
    google = {
      source  = "hashicorp/google"
      version = "6.8.0"
    }
  }
}

provider "google" {
  credentials = file("gcp-key.json")   # Path to your JSON key
  project     = "expanded-theory-468003-g2"  # Replace with your GCP project ID
  region      = "us-central1"
  zone        = "us-central1-c"
}

# 1️⃣ Create VPC
resource "google_compute_network" "vpc_network" {
  name                    = "terraform-vpc"
  auto_create_subnetworks = false
}

# 2️⃣ Create Subnet
resource "google_compute_subnetwork" "subnet" {
  name          = "terraform-subnet"
  ip_cidr_range = "10.0.0.0/24"
  region        = "us-central1"
  network       = google_compute_network.vpc_network.id
}

# 3️⃣ Create Firewall Rule (allow HTTP traffic)
resource "google_compute_firewall" "allow-http" {
  name    = "allow-http"
  network = google_compute_network.vpc_network.name

  allow {
    protocol = "tcp"
    ports    = ["80"]
  }

  source_ranges = ["0.0.0.0/0"]
  target_tags   = ["web"]
}

# 4️⃣ Create VM
resource "google_compute_instance" "vm_instance" {
  name         = "terraform-instance"
  machine_type = "f1-micro"
  tags         = ["web"]

  boot_disk {
    initialize_params {
      image = "debian-cloud/debian-11"
    }
  }

  network_interface {
    network    = google_compute_network.vpc_network.id
    subnetwork = google_compute_subnetwork.subnet.id

    access_config {
      # Required for external IP
    }
  }
}
